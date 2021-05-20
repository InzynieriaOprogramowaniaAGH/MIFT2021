pipeline {
	agent any
	
	tools {
		nodejs "node"
	}
	
	stages {
		stage('build'){
			steps {
				echo 'budowanie'
				sh 'npm install'
			}
			post {

		failure{
			emailext attachLog: true,
			body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
			to: 'mpowrozek@student.agh.edu.pl',
			subject: "Build failed"
		}	
		always{
			echo 'zakonczono'
		}
		success{
			echo 'udalo sie'
			emailext attachLog: true,
			body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
			to: 'mpowrozek@student.agh.edu.pl',
			subject: "Build succedded"
		}
	}	
	
			}
		stage('test') {
			steps {
				echo 'testowanie'
				sh 'npm test'
			}
			post {

		failure{
			emailext attachLog: true,
			body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
			to: 'mpowrozek@student.agh.edu.pl',
			subject: "test failed"
		}	
		always{
			echo 'zakonczono'
		}
		success{
			echo 'udalo sie'
		}
	}
		}
		
		stage('Deploy') {
  		 steps {
                echo 'deployowanie'
                sh 'docker build -t node-chat-deploy -f Dockerfile.deploy .'
            }
            post {
		    	success {
			    echo 'deploy udany!'
			    emailext attachLog: true,
				body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
				to: 'iluzjionist99@gmail.com',
				subject: "success deploy"
		    	}
		    	
			failure {
			    echo 'deploy nieudany :('
			    emailext attachLog: true,
				body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
				to: 'iluzjionist99@gmail.com',
				subject: "error"
			}
    		}
		
	}
			
}
}
