pipeline {
	agent any
	
	tools {nodejs "node" }

	stages{
		stage('Build'){
			steps{
				
				echo 'Building..'
				sh 'npm install'
			}
			post{
		failure{
			emailext attachLog: true,
				body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                		to: 'bartekc007@gmail.com',
                		subject: "Jenkins build failed: Job ${env.JOB_NAME} ${currentBuild.currentResult}"
		}
		success{
			emailext attachLog: true,
                		body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                		to: 'bartekc007@gmail.com',
                		subject: "Jenkins build succeed: Job ${env.JOB_NAME} ${currentBuild.currentResult}"

    		}
	}
			
		}
		stage('Test'){
			steps{
				echo 'Testing..'
				sh 'npm run test'
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
                		subject: "Jenkins test succeed: Job ${env.JOB_NAME} ${currentBuild.currentResult}"

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
				body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                		to: 'bartekc007@gmail.com',
                		subject: "Jenkins deploy failed: Job ${env.JOB_NAME} ${currentBuild.currentResult}"
		}
		success{
			emailext attachLog: true,
                		body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                		to: 'bartekc007@gmail.com',
                		subject: "Jenkins deploy succeed: Job ${env.JOB_NAME} ${currentBuild.currentResult}"

    		}
	}
		}
    		
  	}
  	post{
		failure{
			emailext attachLog: true,
				body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                		to: 'bartekc007@gmail.com',
                		subject: "Jenkins build failed: Job ${env.JOB_NAME} ${currentBuild.currentResult}"
		}
		success{
			emailext attachLog: true,
                		body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                		to: 'bartekc007@gmail.com',
                		subject: "Jenkins build succeed: Job ${env.JOB_NAME} ${currentBuild.currentResult}"

    		}
	}
	
}
