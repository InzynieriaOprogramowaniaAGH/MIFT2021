pipeline {
    agent any 
    
    tools {nodejs "node"}
    
    
    
    stages {
        stage('Test') { 
            steps {
                echo 'Testing'
                sh 'npm install'
                sh 'npm run test'
            }
        }
    }

    post {
        failure {
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                to: 'mserwaczak@gmail.com',
                subject: "Build failed"
        }
        success {
            echo 'Success'
        }
    }
}
