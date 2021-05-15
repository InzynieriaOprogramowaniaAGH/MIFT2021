pipeline {
	agent any
	
	tools {nodejs "node" }

	stages{
		stage('Build'){
			steps{
				echo 'Building...'
				sh 'npm install'
			}
			post{
				failure{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
						to: 'fanofgrin@gmail.com',
						subject: "Jenkins build-stage failed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
				}
				success{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
						to: 'fanofgrin@gmail.com',
						subject: "Jenkins build-stage succeed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
				}
			}	
		}
		stage('Test'){
			steps{
				echo 'Testing...'
				sh 'npm run test'
			}
			post{
				failure{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
						to: 'fanofgrin@gmail.com',
						subject: "Jenkins test-stage failed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
				}
				success{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
						to: 'fanofgrin@gmail.com',
						subject: "Jenkins test-stage succeed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
				}
			}
		}
		stage('Deploy'){
			steps{
				echo 'Deploying...'
				sh 'docker build -t deploy -f Dockerfile_deploy .'
			}
			post{
				failure{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
						to: 'fanofgrin@gmail.com',
						subject: "Jenkins deploy-stage failed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
				}
				success{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
						to: 'fanofgrin@gmail.com',
						subject: "Jenkins deploy-stage succeed ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
				}
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
