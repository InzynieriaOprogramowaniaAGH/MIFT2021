pipeline{
    agent any
    stages{
        stage('Build'){
            steps{
                echo 'Building' 
                sh 'npm install'
                sh 'npm run build'
                
            }
            post{
                success{
                    emailext body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER} - build stage passed",
                        subject: "Success Jenkins build stage: Job ${env.JOB_NAME}",
                        to: 'karolkawalec99@gmail.com'
                }
                failure{
                    emailext body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER} - build stage failed",
                        subject: "Failed Jenkins build stage: Job ${env.JOB_NAME}",
                        to: 'karolkawalec99@gmail.com' 
                    sh 'false'
                }
            }
        }
        stage('Test'){
            steps{
                echo 'Testing'
                sh 'npm run test'
            }
            post{
                success{
                    emailext body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER} - test stage passed",
                        subject: "Success Jenkins test stage: Job ${env.JOB_NAME}",
                        to: 'karolkawalec99@gmail.com'
                }
                failure{
                    emailext body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER} - test stage failed",
                        subject: "Failed Jenkins test stage: Job ${env.JOB_NAME}",
                        to: 'karolkawalec99@gmail.com' 
                    sh 'false'
                }
            }
        }
        stage('Deploy'){
            steps{
                echo 'Deploying'
                sh ' docker build -t deltachat -f docker/Dockerfile.deploy . '
            }
            post{
                success{
                    emailext body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER} - deploy stage passed",
                        subject: "Success Jenkins deploy stage: Job ${env.JOB_NAME}",
                        to: 'karolkawalec99@gmail.com'
                }
                failure{
                    emailext body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER} - deploy stage failed",
                        subject: "Failed Jenkins deploy stage: Job ${env.JOB_NAME}",
                        to: 'karolkawalec99@gmail.com' 
                    sh 'false'
                }
            }
        }
    }
    post{
        success{
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                subject: "Success Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}",
                to: 'karolkawalec99@gmail.com'
        }
        failure{
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                subject: "Failure Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}",
                to: 'karolkawalec99@gmail.com'
        }
    }
}
