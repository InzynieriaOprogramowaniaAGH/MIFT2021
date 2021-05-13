pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building ...'
                sh 'docker build -t build-agent . -f Dockerfile_Build'
            }
            post {
                success {
                    emailext subject: "Pipeline ${env.JOB_NAME} build succeded",
                        body: "Job ${env.JOB_NAME} ${currentBuild.currentResult}: build ${env.BUILD_DISPLAY_NAME}",
                        to: 'grzesiekc188@gmail.com'
                }
                failure {
                    emailext attachLog: true,
                        subject: "Pipeline ${env.JOB_NAME} build failed",
                        body: "Job ${env.JOB_NAME} ${currentBuild.currentResult}: build ${env.BUILD_DISPLAY_NAME}",
                        to: 'grzesiekc188@gmail.com'
                }
            }
        }
        stage('Test') {
            steps {
                echo 'Testing ...'
                sh 'docker build -t test-agent . -f Dockerfile_Test'
            }
            post {
                success {
                    emailext subject: "Pipeline ${env.JOB_NAME} tests succeded",
                        body: "Job ${env.JOB_NAME} ${currentBuild.currentResult}: build ${env.BUILD_DISPLAY_NAME}",
                        to: 'grzesiekc188@gmail.com'
                }
                failure {
                    emailext attachLog: true,
                        subject: "Pipeline ${env.JOB_NAME} tests failed",
                        body: "Job ${env.JOB_NAME} ${currentBuild.currentResult}: build ${env.BUILD_DISPLAY_NAME}",
                        to: 'grzesiekc188@gmail.com'
                }
            }
        }
    }
}
