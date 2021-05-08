pipeline {
    agent any 
    
    tools {nodejs "node"}
    
    stages {
        stage('Build') { 
            steps {
                echo 'Building..'
                sh 'npm install'
                
            }
            post {
        	failure {
            		emailext attachLog: true,
                	body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                	to: 'mserwaczak@gmail.com',
                	subject: "Build failed"
        	}
        	success {
            		emailext attachLog: true,
                	body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                	to: 'mserwaczak@gmail.com',
                	subject: "Build success"
        	}
    		}
        }

    
    
    
        stage('Test') { 
            steps {
                echo 'Testing..'
                sh 'npm run test'
            }
            post {
        	failure {
            		emailext attachLog: true,
                	body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                	to: 'mserwaczak@gmail.com',
                	subject: "Test failed"
        	}
        	success {
            		echo 'Success'
        	}
    		}
        }
    }

    
}
