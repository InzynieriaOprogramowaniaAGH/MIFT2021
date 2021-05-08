pipeline{
    agent any

tools {nodejs "nd"}
    
    stages{
        stage('Test'){
            steps{
                echo 'Testing app...'
                sh 'npm install'
                sh 'npm run test' 
            }     
        }    
    }
    post{
        failure{
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: ${currentBuild.fullDisplayName}",
                to: 'olakrason1999@gmail.com',
                subject: "Jenkins build failed ${env.BUILD_NUMBER}"
        }
        success{
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: ${currentBuild.fullDisplayName}",
                to: 'olakrason1999@gmail.com',
                subject: "Jenkins build succeed ${env.BUILD_NUMBER}"
        }
    } 

    
}
