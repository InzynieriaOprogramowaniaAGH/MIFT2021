pipeline{
    agent any
    stages{
        stage('Build'){
            steps{
                echo 'Building' 
                sh 'npm install'
                sh 'npm run build'
            }
        }
        stage('Test'){
            steps{
                echo 'Testing'
                sh 'npm run test'
            }
        }
    }
    post{
        success{
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                recipientProviders: [developers(), requestor()],
                subject: "Success Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}",
                to: 'karolkawalec99@gmail.com'
        }
        failure{
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                recipientProviders: [developers(), requestor()],
                subject: "Failure Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}",
                to: 'karolkawalec99@gmail.com'
        }
    }
}
