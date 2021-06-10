pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                sh '''
                echo 'Building..'
                apt -y update
                apt -y upgrade
                apt install sudo -y
                apt install curl
                curl -sL https://deb.nodesource.com/setup_14.x | sudo -E bash -
                apt -y install nodejs
                node --version
                npm --version
                git pull origin master
                npm install
                npm run build
                '''
            }
                
            post {
                success {
                    echo 'Success!'
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                    recipientProviders: [developers(), requestor()],
                    subject: "Success Jenkins Build",
                    to: 'krzysiek.klim1999@gmail.com'
                }
            
                failure {
                    echo 'Failure!'
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                    recipientProviders: [developers(), requestor()],
                    subject: "Failed Jenkins Build",
                    to: 'krzysiek.klim1999@gmail.com'
                }
            }
        }
         
        stage('Test') {
            steps {
                sh '''
                echo 'Testing..'
                npm test
                '''
                }

            post {
                success {
                    echo 'Success!'
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                    recipientProviders: [developers(), requestor()],
                    subject: "Success Jenkins Test ${currentBuild.currentResult}: Job ${env.JOB_NAME}",
                    to: 'krzysiek.klim1999@gmail.com'
                }
        
                failure {
                    echo 'Failure!'
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                    recipientProviders: [developers(), requestor()],
                    subject: "Failed Jenkins Test ${currentBuild.currentResult}: Job ${env.JOB_NAME}",
                    to: 'krzysiek.klim1999@gmail.com'
                }
            }
        }

        stage('Deploy') {
            steps {
                sh '''
                echo 'Deploying..'
                docker build -t deltachat-deploy -f Dockerfile-deploy .
                '''
            }
            post {
                success {
                    echo 'Success!'
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                    recipientProviders: [developers(), requestor()],
                    subject: "Success Jenkins Deploy ${currentBuild.currentResult}: Job ${env.JOB_NAME}",
                    to: 'krzysiek.klim1999@gmail.com'
                }
        
                failure {
                    echo 'Failure!'
                    emailext attachLog: true,
                    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                    recipientProviders: [developers(), requestor()],
                    subject: "Failed Jenkins Deploy ${currentBuild.currentResult}: Job ${env.JOB_NAME}",
                    to: 'krzysiek.klim1999@gmail.com'
                }
            }
        }

    }
}
