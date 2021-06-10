
1. 
Rozpoczęto od konfiguracji Jenkinsa, w tym celu dodano usera `ghmanager` (aby zachować separację kredencjałów użytkownika/admina od tych, które są wykorzystywane w infrastrukturze) i dla niego wygenerowano API Token.

Następnie opracowano zawartość git-hooka z polecenia:

```shell
#!/bin/sh

echo 'starting node-chat-bundle build...';
curl -u ghmanager:117...cea -X POST http://localhost:8080/job/node-chat-bundle/buildWithParameters?token=117...cea
```

gdzie 117...cea ← pełny API Token dla użytkownika `ghmanager`.

Konieczne tutaj bylo zastosowanie route `/buildWithParameters` ze względu na zastosowanie parametrów w buildzie. W przypadku samego `/build` pojawiał się bład.

2. Zweryfikowano automatyczne wyzwyalanie builda po commicie.

3. Rozszerzono Jenkinsfile o stage "Deploy", dodatkowo dodano polecenie `sh "git clean -dxf"` w bloku `always`.

```groovy
def repoUrl = 'https://github.com/InzynieriaOprogramowaniaAGH/MIFT2021/'
def defaultBranch = 'Grupa05'
def repoWorkspacePath = 'Grupy/Grupa05/JS283683/workspace'
def dockerfilesPath = "${repoWorkspacePath}/Docker"

def log(str,lvl='INFO') { println("[BUILD_${lvl}] ${str}") }
def testImageName = 'test_agent'
def repositoryName = "szumied"
def releaseImageName = 'node_chat_starter'
def buildImageName = 'build_agent'

pipeline {
    agent any
    options { disableConcurrentBuilds() }
    parameters {
        string(name: 'BRANCH', defaultValue: defaultBranch, description: 'MIFT2021 repo branch')
        booleanParam(name: 'RELEASE', defaultValue: false, description: 'Should artifacts be published when successful?')
    }
    triggers {
        cron('H 3 * * *')
    }
    stages {
        stage('Preparation: SCM'){
            steps {
                checkout([$class: 'GitSCM',
                  branches: [[name: params.BRANCH]],
                  extensions: [],
                  userRemoteConfigs: [[url: repoUrl]]])
                withCredentials([usernamePassword(credentialsId: 'DOCKERHUB', passwordVariable: 'dockerPass', usernameVariable: 'dockerUser')]) {
                    sh "echo ${dockerPass} | docker login -u ${dockerUser} --password-stdin"
                }
            }
        }
        stage('Build') {
            steps {
                log "Build stage running:"
                script {
                    dir(dockerfilesPath) {
                        def dockerfilePath = './build_agent'
                        def imageName = "${repositoryName}/${buildImageName}:${env.BUILD_ID}"
                        def buildAgentImage = docker.build(imageName, dockerfilePath)
                        log "${buildAgentImage}"
                        log "${buildAgentImage.id}"
                        buildAgentImage.push('latest')
                    }
                }
            }
        }
        stage('Test') {
            steps {
                 script {
                    dir(dockerfilesPath) {
                        def dockerfilePath = './test_agent'
                        def imageName = "${testImageName}:${env.BUILD_ID}"
                        def testAgentImage = docker.build(imageName, dockerfilePath).withRun("-t") { container ->
                            sh "docker exec -i ${container.id} cat 'node-chat-app/test_result.log' > ${WORKSPACE}/test_result.log"
                        }
                    }
                 }
            }
        }
        stage('Deploy') {
            when {
                expression { params.RELEASE }
            }
            steps {
                script {
                    dir(dockerfilesPath) {
                        def dockerfilePath = './starter_agent'
                        def imageName = "${repositoryName}/${releaseImageName}:${env.BUILD_ID}"
                        def releaseImage = docker.build(imageName, dockerfilePath)
                        releaseImage.push("${env.BUILD_ID}")
                        releaseImage.push('latest')
                    }
                }
            }
        }
        stage('Archive artifacts') {
            steps {
                archiveArtifacts artifacts: '**/test_result.log', allowEmptyArchive: true
            }
        }
    }
    post {
        always {
            log 'Build execution stopped.'
            script {
                sh "git clean -dxf" // Possible: docker prune
            }
        }
        success {
            log 'Result: Build succeeded'
        }
        unstable {
            log 'Result: Build unstable, some tests failed'
        }
        failure {
            log 'Result: Build failure'
        }
    }
}
```

Jako artefakt do deployu uznano publiczny obraz "starter_agent", który (w przypadku gdy wybierze sie parametr "RELEASE" i poprzednie stage'e przejdą pomyślnie) jest publikowany na Docker Hub, i jest zbudowany w oparciu o Dockerfile przygotowany w ten sposób, aby użytkownik mógł po prostu uruchomic kontener poleceniem:
`docker run -p 3000:3000 szumied/node_chat_starter:latest`

Treść opracowanego Dockerfile'a:

```
FROM szumied/build_agent:latest
EXPOSE 3000
WORKDIR "node-chat-app"
CMD ["npm", "start"]
```

Deploy jest tu wykonywany na dedykowany kontener dockerowy, a do deploya przekazywany jest artefakt (build_agent) stworzony w stage'u "Build". Pipeline przechodzi wszystkie polecone etapy, natomiast nie jest uruchamiany z osobnego repo, aby zachować ciągłość pracy na repozytorium MIFT2021. Wiadomo, w przypadku pracy nad własną aplikacją, trzeba by pracować na plikach we własnym repozytorium, wtedy rekonfiguracja przygotowanego procesu CI/CD nie jest trudna, wystarczyłoby zmienić ścieżkę do repozytorium w Jenkinsie, no i w Dockerfile'u buildowym, który zaciąga kod aplikacji.
Jako powiadomienia dla użytkowników Jenkinsa służą końcowe wiadomości i rezultat builda - najmniej natarczywa opcja dla osób zainteresowanych. Istnieje także możliwość uruchomienia Jenkinsowych powiadomień przez popupy systemowe z przeglądarki.
