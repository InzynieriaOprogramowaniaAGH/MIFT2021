pipeline {
	agent any
	
	tools {nodejs "node"}
	
	stages {
		stage('test') {
			steps {
				echo 'testowanie'
				sh 'npm install'
				sh 'npm run test'
			}
		}
	}
			post {

		failure{
			emailtext attachLog: true,
			body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
			to: 'mpowrozek@student.agh.edu.pl',
			subject: "test failed"
		}	
		success{
			echo 'udalo sie'
		}
	}
}
