pipeline {
	agent any
	
	tools {nodejs "node" }
	
	stages{
		stage('Build') {
			steps{
				echo 'Building...'
				sh 'npm install'
			}
		}
		stage('Test') {
			when {
              			expression {currentBuild.result == null || currentBuild.result == 'SUCCESS'}
            		}
            		steps {
                		echo 'Testing..'
				sh 'npm test'
            		}
		}
		stage('Deploy') {
            		steps {
                		echo 'Deploying....'
            		}
        	}
	}
	post{
		failure{
			emailext attachLog: true,
				body: "Jenkins ${env.JOB_NAME} ended with status: ${currentBuild.currentResult}",
                		to: 'szymonxlorenc@gmail.com',
				subject: "${env.JOB_NAME}: ${currentBuild.currentResult}"
		}
		success{
			emailext attachLog: true,
                		body: "Jenkins builded and tested with status: ${currentBuild.currentResult} of job ${env.JOB_NAME}",
                		to: 'szymonxlorenc@gmail.com',
				subject: "${env.JOB_NAME}: ${currentBuild.currentResult}"
		}		
	}
}
