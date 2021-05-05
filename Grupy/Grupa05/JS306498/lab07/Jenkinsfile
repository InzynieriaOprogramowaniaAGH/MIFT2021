pipeline {

    agent any
	tools{nodejs "NodeJS"}
    stages {
        
        stage('Test') {
            steps {
                echo 'Test...'
		sh 'npm installwwa'
                sh 'npm run test'
            }
        }
    }
    
    post {
    
    	always {
    	    echo 'End'
    	}
    	
    	success {
	    echo 'Success'
    	}
    	
        failure {
            echo 'Failure'
            emailext attachLog: true,
                body: "${currentBuild.currentResult}:  build ${env.BUILD_NUMBER} Job ${env.JOB_NAME}",
                to: 'sosinkuba99@gmail.com',
                subject: "Result-test failed"
        }
    }
}
