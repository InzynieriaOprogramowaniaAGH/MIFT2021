#!/usr/bin/env groovy
pipeline {
    agent {
        docker { image 'node:14-alpine' }
    }

    environment {
        FAILED = false
    }

    stages {
        stage('Build') {
            steps {
                git branch: 'dev', url: 'https://github.com/Tituu/node-chat.git'
                sh 'git pull'
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
                when ( env.FAILED ) {
                    expression {
                        currentBuild.result = 'ABORTED'
                        error('Build failed! Stopping…')
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
        // stage('Deploy') {
        //     steps {
        //         sh 'git fetch --all'
        //         sh 'git checkout master'
        //         sh "git merge  ${env.BRANCH_NAME}"    
        //     }
        //     post {
        //         failure {
        //             mail to: 'adrianhebda22@gmail.com',
        //             subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
        //         }
        //     }
        // }
    }
}