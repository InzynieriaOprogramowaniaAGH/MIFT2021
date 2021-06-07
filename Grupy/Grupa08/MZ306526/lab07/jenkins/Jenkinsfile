pipeline {
    agent any

    tools { nodejs "node"}

    stages {
        stage('Test') {
            steps {
                echo 'Testing..'
                sh 'npm install'
                sh 'npm test'
            }
        }
    }
    post {
        failure {
            echo 'Success'
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                recipientProviders: [developers(), requestor()],
                to: 'michalzma@gmail.com',
                subject: "Build failed in Jenkins"
        }
        success {
            echo 'Fail'
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                recipientProviders: [developers(), requestor()],
                to: 'michalzma@gmail.com',
                subject: "Successful build in Jenkins"
        }
    }
}
