pipeline {
    agent {
        docker { image 'node:latest' } 
    }

    stages {
    
    	stage('Build') {
            steps {
               echo 'Building..'
		checkout scm
		sh 'npm install'
		sh 'npm run build'
            }
        }
	post {
		success {
			echo 'Success!'
			emailext attachLog: true,
				body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
				to: 'fedirko@student.agh.edu.pl',
				subject: "Successful build in Jenkins"
    		
		}
		failure {
			echo 'Failure!'
			emailext attachLog: true,
			    body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
			    to: 'fedirko@student.agh.edu.pl',
			    subject: "Build failed in Jenkins"
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
        
        stage('Deploy'){
		steps{
			echo 'Deploying..'
			sh 'docker build -t delta-chat -f Dockerfile.deploy .'
		}
		post {
			success {
				echo 'Success!'
				emailext attachLog: true,
				body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
				to: 'fedirko@student.agh.edu.pl',
				subject: "Successful deploy in Jenkins"
			}
			failure {
				echo 'Failure!'
				emailext attachLog: true,
				body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
				to: 'fedirko@student.agh.edu.pl',
				subject: "Deploy failed in Jenkins"
			}
		}
	}
        
    }
    post {
    	success {
    	    echo 'Success!'
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                to: 'fedirko@student.agh.edu.pl',
                subject: "Successful test in Jenkins"
    		
    	}
    	failure {
            echo 'Failure!'
            emailext attachLog: true,
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                to: 'fedirko@student.agh.edu.pl',
                subject: "Test failed in Jenkins"
        }
    }
}
