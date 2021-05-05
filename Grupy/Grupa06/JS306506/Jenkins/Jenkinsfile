pipeline {
	agent any
	
	tools {nodejs "node" }

	stages{
		stage('Test'){
			steps{
				echo 'Testing...'
				sh 'npm install'
				sh 'npm run test'
			}
		}
	}
	post{
		failure{
			emailext attachLog: true,
				body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		to: 'fanofgrin@gmail.com',
                		subject: "Jenkins build failed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
		}
		success{
			emailext attachLog: true,
                		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		to: 'fanofgrin@gmail.com',
                		subject: "Jenkins build succeed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
		}		
	}
}
