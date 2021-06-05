pipeline {
    agent any
	
    stages {
            stage('Test') {
            steps {
            	echo 'Testing'
		git url: 'https://github.com/TurboReal/deltachat-desktop'
		dir('Docker'){
			sh '~/docker-compose up test-app'
		}
                
            }
            post{
	    	success{
			echo 'Testing - success'
	    		emailext attachLog: true,
		    		body: "Status: ${currentBuild.currentResult}",
		    		recipientProviders: [[$class: 'DevelopersRecipientProvider']],
		    		subject: 'Test Succeed',
		    		to: 'turboreal9812@gmail.com'
	    		
	    	}
		failure{
			echo 'Testing - failure'
	    		emailext attachLog: true,
		    		body: "Status: ${currentBuild.currentResult}",
		    		recipientProviders: [developers()],
		    		subject: 'Test failed',
		    		to: 'turboreal9812@gmail.com'
	    	}
	    }
        }
    }
}
