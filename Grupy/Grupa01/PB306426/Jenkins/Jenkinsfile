pipeline {
    agent any 
    tools {nodejs "node"}
    stages {
        stage('Build') { 
            steps {
                echo 'Building'
                sh 'npm install'
                sh 'npm run start'
            }
            post {
                failure {
                    emailext attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'xxpazindorxx@gmail.com',
                        subject: "Buildddd failed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                }
                success {
                    emailext attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'xxpazindorxx@gmail.com',
                        subject: "Build successful ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                }
            }
        }
        stage('Test') { 
            steps {
                echo 'Testing'
                sh 'npm run test'
            }
            post {
                failure {
                    emailext attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'xxpazindorxx@gmail.com',
                        subject: "Test failed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                }
                success {
                    emailext attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'xxpazindorxx@gmail.com',
                        subject: "Test successful ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                }
            }
        }
        stage('Deploy') { 
            steps {
                echo 'Deploy'
                sh 'docker build -t node-chat ./'
            }
            post {
                failure {
                    emailext attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'xxpazindorxx@gmail.com',
                        subject: "Deploy failed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                }
                success {
                    emailext attachLog: true,
                        body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                        recipientProviders: [developers(), requestor()],
                        to: 'xxpazindorxx@gmail.com',
                        subject: "Deploy successful ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
                }
            }
        }
    }  
}
