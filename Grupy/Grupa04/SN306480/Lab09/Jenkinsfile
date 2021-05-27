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
					echo 'Failure'
					emailext attachLog: true,
					body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
					to: 'szymonn45@gmail.com',
					subject: "Build failed"
				}
				success{
					echo 'Success'
					emailext attachLog: true,
					body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
					to: 'szymonn45@gmail.com',
					subject: "Build success"
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
					echo 'Failure'
					emailext attachLog: true,
					body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
					to: 'szymonn45@gmail.com',
					subject: "Test failed"
				}
				success{
					echo 'Success'
					emailext attachLog: true,
					body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
					to: 'szymonn45@gmail.com',
					subject: "Test success"
				}
			}
		}

		stage('Deploy') {
			steps {
				echo 'Deploy'
				sh 'docker build -t deploy -f Dockerfile_socketio_deploy .'
			}
			post{
				always{
					echo 'Finished'
				}
				failure{
					echo 'Failure'
					emailext attachLog: true,
					body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
					to: 'szymonn45@gmail.com',
					subject: "Deploy failed"
				}
				success{
					echo 'Success'
					emailext attachLog: true,
					body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
					to: 'szymonn45@gmail.com',
					subject: "Deploy success"
				}
			}
		}
	}
}
