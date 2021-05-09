#!/usr/bin/env groovy
pipeline {
    agent {
        docker { image 'node:14-alpine' }
    }

    stages {
        stage('Build') {
            steps {
                git branch: 'dev', url: 'https://github.com/Tituu/node-chat.git'
                sh 'npm install'
            }
        }
        stage('Test') {
            steps {
                sh 'npm run test'
            }
            post {
                failure {
                    mail to: 'adrianhebda22@gmail.com',
                        subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Something is wrong with ${env.BUILD_URL}"
                    sh 'exit 1'
                }
                success {
                    mail to: 'adrianhebda22@gmail.com',
                        subject: "Success Pipeline: ${currentBuild.fullDisplayName}",
                        body: "Success building ${env.BUILD_URL} "
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