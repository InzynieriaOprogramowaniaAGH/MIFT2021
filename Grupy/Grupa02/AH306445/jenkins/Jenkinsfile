#!/usr/bin/env groovy
pipeline {
    agent any
    environment {
        FAILED = false
    }
    tools {nodejs "node"}

    stages {
        stage('Build') {
            steps {
                git branch: 'dev', url: 'https://github.com/Tituu/node-chat.git'
                sh 'npm install > log_build.txt'
            }
            post {
                failure {
                    script {
                        env.FAILED = true
                    }  

                    emailext attachLog: true,
                        attachmentsPattern: 'log_build.txt',
                        to:'adrianhebda22@gmail.com',
                        subject: "Failed Build stage in Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Something is wrong with ${env.BUILD_URL}"     
                      
                }
                success {
                    mail to: 'adrianhebda22@gmail.com',
                        subject: "Success Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Success building ${env.BUILD_URL} "                        
                }
            }
        }
        stage('Test') {
            steps {
                script{
                    if(env.FAILED == true){
                        expression {
                            currentBuild.result = 'ABORTED'
                            error('Build failed! Stopping…')
                        }
                    }
                }
                sh 'npm run test > log.txt'
            }
            post {
                failure {
                    emailext attachLog: true,
                        attachmentsPattern: 'log.txt',
                        to:'adrianhebda22@gmail.com',
                        subject: "Failed Test stage in Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Something is wrong with ${env.BUILD_URL}"        
                }
                success {
                    mail to: 'adrianhebda22@gmail.com',
                        subject: "Success Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Success testing ${env.BUILD_URL} "                        
                }
            }
        } 

        stage('Deploy'){
            steps {
                sh '''
                echo 'Deploying..'
                docker build -t node-chat-deploy -f deploy.Dockerfile .
                docker run node-chat-deploy
                '''
            }
            post {
                failure {
                    emailext attachLog: true,
                        attachmentsPattern: 'log.txt',
                        to:'adrianhebda22@gmail.com',
                        subject: "Failed Deploy stage in Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Something is wrong with ${env.BUILD_URL}"        
                }
                success {
                    mail to: 'adrianhebda22@gmail.com',
                        subject: "Success Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Success deploying ${env.BUILD_URL} "                        
                }
            }
        }
    }
}