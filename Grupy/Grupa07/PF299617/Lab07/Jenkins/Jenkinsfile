pipeline {
    agent any

    stages {
    
    	stage('Build') {
            steps {
               echo 'Building..'
		sh 'npm install'
		sh 'npm run build'
            }
        }
        
        stage('Test') {
            steps {
               echo 'Testing..'
               sh 'npm test'
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
