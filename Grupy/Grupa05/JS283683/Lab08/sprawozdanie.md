1. Rozszerzono Jenkinsfile z poprzedniego laboratorium o stage budujący. Wykorzystano w tym celu przygotowany plik Dockerfile, ktory wstępnie przygotowuje środowisko uruchomieniowe (jest to "build" na tyle, na ile mozna to rozumieć w JavaScripcie, który jest językiem dynamicznym i w którym - bez wykorzystywania odpowiednich narzędzi - nie mamy typowego procesu kompilacji, w czasie którego można zbadać np. poprawność typów lub składni), weryfikuje oraz sprawdza zależności pakietów:

```
FROM ubuntu:latest
ENV TIME_ZONE=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TIME_ZONE /etc/localtime && echo $TIME_ZONE > /etc/timezone
RUN apt-get update
RUN apt-get install -y git npm
RUN git clone https://github.com/binhxn/node-chat-app.git
RUN cd node-chat-app; npm install
```

Jenkinsfile:

```groovy
def repoUrl = 'https://github.com/InzynieriaOprogramowaniaAGH/MIFT2021/'
def defaultBranch = 'Grupa05'
def repoWorkspacePath = 'Grupy/Grupa05/JS283683/workspace'
def dockerfilesPath = "${repoWorkspacePath}/Docker"

def log(str,lvl='INFO') { println("[BUILD_${lvl}] ${str}") }
def testImageName = 'test_agent'
def repositoryName = "szumied"
def buildImageName = 'build_agent'

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

4. Tresc przygotowanego git-hooka (zawartosc pliku `post-commit`)

```shell
#!/bin/sh
echo 'To jest commit hook, który będzie kiedyś uruchamiał Pipeline po każdym nowym commicie'
```

Końcowo dołączono screeny i wrzucono do repozytorium.