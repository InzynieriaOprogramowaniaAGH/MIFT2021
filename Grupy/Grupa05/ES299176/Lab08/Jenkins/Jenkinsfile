pipeline{
	agent any
	tools {
		nodejs "NodeJS"
	}
	stages {
		stage('Build') {
			steps {
				echo 'Building'
				sh 'npm install'
			}
			post{

				always{
					echo 'Finished'
				}
				failure{
					sendMessage('build', 'Failure')
				}
				success{
					sendMessage('build', 'Success')
				}
			}
		}
		stage('Test') {
			steps {
				echo 'Testing'
				sh 'npm run test'
			}
			post{

				always{
					echo 'Finished'
				}
				failure{
					sendMessage('test', 'Failure')
				}
				success{
					sendMessage('test', 'Success')
				}
			}
		}
	}
	
}

def sendMessage(stage, status) {
	echo status
	emailext attachLog: true,
		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
		to: 'eszczupak82@gmail.com',
		subject: stage + " " + status
}


