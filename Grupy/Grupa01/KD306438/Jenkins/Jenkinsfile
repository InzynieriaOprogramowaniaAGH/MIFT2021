pipeline {
    agent any 
    tools {
     nodejs "node"
    }
    stages {
        stage('Build') { 
            steps {
                echo 'Building... '
                sh 'git checkout master'
                sh 'git pull'
                sh 'npm install'          
            }
            
             post {
               failure {
                  emailext attachLog: true,
                     body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                     recipientProviders: [developers(), requestor()],
                     to: 'laj72321@gmail.com',
                     subject: "Fail while building in Jenkins"
                }
               success {
                  emailext attachLog: true,
                     body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                     recipientProviders: [developers(), requestor()],
                     to: 'laj72321@gmail.com',
                     subject: "Success while building in Jenkins"
                }
             }
        }

        stage('Test') {  
            steps {
                script {
                   if (currentBuild.result == 'UNSTABLE' || currentBuild.result == 'FAILURE')
                      error('Build failed, pipeline is not continued')
                }
                echo 'Testing...'
                sh 'npm install'
                sh 'npm run test'
            }
            
            post {
               failure {
                  emailext attachLog: true,
                     body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                     recipientProviders: [developers(), requestor()],
                     to: 'laj72321@gmail.com',
                     subject: "Fail while testing in Jenkins"
               }
               success {
                  emailext attachLog: true,
                     body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                     recipientProviders: [developers(), requestor()],
                     to: 'laj72321@gmail.com',
                     subject: "Success while testing in Jenkins"
              }
          }
        }
        
        stage('Deploy') { 
            steps {
                echo 'Deploying... '
                sh 'docker build -t node-chat .'        
            }
            
             post {
               failure {
                  emailext attachLog: true,
                     body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                     recipientProviders: [developers(), requestor()],
                     to: 'laj72321@gmail.com',
                     subject: "Fail while deploying in Jenkins"
                }
               success {
                  emailext attachLog: true,
                     body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                     recipientProviders: [developers(), requestor()],
                     to: 'laj72321@gmail.com',
                     subject: "Success while deploying in Jenkins"
                }
             }
        }
    }
    
}
