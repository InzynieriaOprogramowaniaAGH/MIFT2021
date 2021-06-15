pipeline{
	agent any
	tools {nodejs "nodejs"}
	stages{
		stage('Build') {
            		steps {
                		echo 'Building'
				checkout scm
				sh 'npm install'
				sh 'npm run build'
            		}
        	}
		stage('Test'){
			when {
				expression {currentBuild.result == null || currentBuild.result == 'SUCCESS'}
			}
			steps{
				echo 'Testig'
				sh 'npm test'
			}
		}
	}
	
    	post {
        	failure {
            		emailext attachLog: true,
                		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		recipientProviders: [developers(), requestor()],
                		to: 'zmichax@gmail.com',
               			subject: "Build failed in Jenkins ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
        }
        	success {
            		emailext attachLog: true,
                		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                		recipientProviders: [developers(), requestor()],
                		to: 'zmichax@gmail.com,
                		subject: "Successful build in Jenkins ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
        }
    }
    
}
