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