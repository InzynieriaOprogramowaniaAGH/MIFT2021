1. Przygotowano strukturę folderów wedlług polecenia.
```
.
├── Docker
│   ├── build_agent
│   │   └── Dockerfile
│   ├── starter_agent
│   │   └── Dockerfile
│   └── test_agent
│       └── Dockerfile
├── Jenkinsfile
├── docker-compose.yml
└── git-hook 
```

2. Opracowano wstępny Jenkinsfile ze stagem testowym.  M. in. uwzgledniono mozliwosc wskazania różnych gałęzi repozytorium jako parametr.

2.4. Do powyższego pliku dodano stage odpowiedzialny za archiwizację tekstów 

Końcowy Jenkinsfile:
```groovy
def repoUrl = 'https://github.com/InzynieriaOprogramowaniaAGH/MIFT2021/'
def defaultBranch = 'Grupa05'
def repoWorkspacePath = 'Grupy/Grupa05/JS283683/workspace'
def dockerfilesPath = "${repoWorkspacePath}/Docker"

def log(str,lvl='INFO') { println("[BUILD_${lvl}] ${str}") }
def testImageName = 'test_agent'
def repositoryName = "szumied"

pipeline {
    agent any
    options { disableConcurrentBuilds() }
    parameters {
        string(name: 'BRANCH', defaultValue: defaultBranch, description: 'MIFT2021 repo branch')
        booleanParam(name: 'RELEASE', defaultValue: false, description: 'Should artifacts be published when successful?')
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
        stage('Archive artifacts') {
            steps {
                archiveArtifacts artifacts: '**/test_result.log', allowEmptyArchive: true
            }
        }
    }
    post {
        always {
            log 'Build execution stopped.'
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

Przygotowany Dockerfile agenta testowego:

```
FROM szumied/build_agent:latest
EXPOSE 3000
WORKDIR "node-chat-app"
CMD ["npm", "start"]
```

3. Z sukcesem wykonano przygotowany stage testowy.

Treść uzyskanego pliku `test_results.log`:
```
> node-chat-app@1.0.0 test /node-chat-app
> mocha server/**/*.test.js



  generateMessage
    âœ“ should generate correct message object

  generateLocationMessage
    âœ“ should generate correct location object

  Users
    âœ“ should find user
    âœ“ should NOT find user
    âœ“ should remove a user
    âœ“ should NOT remove a user
    âœ“ should return names for Lakers Fans
    âœ“ should return names for Fad Diet
    âœ“ should add new user

  isRealString
    âœ“ should reject non-string values
    âœ“ should reject string with only spaces
    âœ“ should allow strings with non-space characters


  12 passing (12ms)

```

4. Zmiany wrzucono do repozytorium MIFT2021.