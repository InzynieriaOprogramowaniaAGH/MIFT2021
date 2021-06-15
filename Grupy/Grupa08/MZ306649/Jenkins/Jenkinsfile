pipeline{
	agent any
	tools {nodejs "nodejs"}
	stages{
		stage('Test'){
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
