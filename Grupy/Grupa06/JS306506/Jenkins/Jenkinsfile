pipeline {
	agent any

	stages{
		stage('Build'){
			steps{
				echo 'Building...'
				sh 'npm install'
			}
		}
		stage('Test'){
			steps{
				echo 'Testing...'
				sh 'npm run test'
		}
	}
	post{
		failure{
			echo "Jenkins build failed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
		}
		success{
			echo "Jenkins build succeed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
		}		
	}
}
