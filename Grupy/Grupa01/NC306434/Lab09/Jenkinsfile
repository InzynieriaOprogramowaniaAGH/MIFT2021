pipeline {
    agent any
	tools{nodejs "NodeJS"}

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'npm install'
            }
            post{
    		success {
    	     		echo 'Success Build'
    	     		emailext attachLog: true,
               		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		to: 'nataliaczachor14@gmail.com',
                		subject: "Success build in Jenkins"
    		}
        	failure {
            		echo 'Failure Build'
            		emailext attachLog: true,
                		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		to: 'nataliaczachor14@gmail.com',
                		subject: "Failed build in Jenkins"
        	} 
    	   }  
        }
        stage('Test') {
            steps {
                echo 'Testing..'
                sh 'npm run test'
            }
            post{
    		success {
    	     		echo 'Success Test'
    	     		emailext attachLog: true,
               		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		to: 'nataliaczachor14@gmail.com',
                		subject: "Success test in Jenkins"
    		}
        	failure {
            		echo 'Failure Test'
            		emailext attachLog: true,
                		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		to: 'nataliaczachor14@gmail.com',
                		subject: "Failed test in Jenkins"
        	} 
    	   }  
        }
        
        stage('Deploy') {
            steps {
                echo 'Deploying..'
                sh 'docker build -t deploy -f Dockerfile.deploy .'
            }
            post{
    		success {
    	     		echo 'Success Deploy'
    	     		emailext attachLog: true,
               		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		to: 'nataliaczachor14@gmail.com',
                		subject: "Success deploy in Jenkins"
    		}
        	failure {
            		echo 'Failure Deploy'
            		emailext attachLog: true,
                		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		to: 'nataliaczachor14@gmail.com',
                		subject: "Failed deploy in Jenkins"
        	} 
    	   }  
        }
        
        
    }
}


