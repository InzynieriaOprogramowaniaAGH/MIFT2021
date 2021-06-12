pipeline {
    agent any

    stages {
        stage('Test') {
            steps {
                echo 'Testing..'
		sh 'npm install'
		sh 'npm test'
            }
        }
        
    }
	post { 
        	always { 
            		echo 'Pipeline finished!'
        }
		failure {
			echo 'Testing failed!'
			emailext attachLog: true,
                		subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
             			body: "Something is wrong with ${env.BUILD_URL}",
                		recipientProviders: [developers(), requestor()],
                		to: 'michalpast034@gmail.com'
             			
    	}
		success {
			echo 'Testing successful!'
			emailext attachLog: true,
                		subject: "Successful Pipeline: ${currentBuild.fullDisplayName}",
             			body: "Everything worked fine",
                		recipientProviders: [developers(), requestor()],
                		to: 'michalpast034@gmail.com'
    	}
    }
}