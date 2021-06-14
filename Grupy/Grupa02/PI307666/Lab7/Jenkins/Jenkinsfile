#!/usr/bin/env groovy
pipeline {
    agent {
        docker {
            image 'node:14-alpine'
            }
    }
    
    stages {
        stage('Build') {
            steps {
                git branch: 'master', url: 'https://github.com/PiotrIzw/node-chat-app'
                sh 'npm install'
                }
            }
        stage('Test') {
            steps {
                sh 'npm run test > log.txt'
            }
            post {
                failure {
                        emailext attachLog: true,
                        attachmentsPattern: 'log.txt',
                        to:'piotr.izworski.0@gmail.com',
                        subject: "Failed Test stage in Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Something is wrong with ${env.BUILD_URL}"        
                }
                success {
                        mail to: 'piotr.izworski.0@gmail.com',
                        subject: "Success Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Success testing ${env.BUILD_URL} "                        
                }
            }
        } 
    }
}
