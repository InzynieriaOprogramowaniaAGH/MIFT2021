pipeline {
	agent any
	
	tools {nodejs "node" }

	stages{
		stage('Build'){
			steps{
				
				echo 'Building...'
				sh 'npm install'
			}
			
		}
		stage('Test'){
			steps{
				echo 'Testing... '
				sh 'npm run test'
			}
			
    		}
    		
  	}
  	post{
		failure{
			emailext attachLog: true,
				body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                		to: 'bartekc007@gmail.com',
                		subject: "Jenkins test failed: Job ${env.JOB_NAME} ${currentBuild.currentResult}"
		}
		success{
			emailext attachLog: true,
                		body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                		to: 'bartekc007@gmail.com',
                		subject: "Jenkins build succeed: Job ${env.JOB_NAME} ${currentBuild.currentResult}"

    		}
	}
	
}
