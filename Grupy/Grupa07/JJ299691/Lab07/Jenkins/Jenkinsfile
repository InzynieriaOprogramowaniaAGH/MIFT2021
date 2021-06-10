pipeline {
    agent any
tools {nodejs "nodejs"}
    stages {
        stage('Build') {
            steps {
		sh 'npm install'
		echo 'Building....'
		}
	}
	stage('Test') {
		steps {
			echo 'Testing....'
			sh 'npm run test'
			
		}
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
    
    post {
    	
    	success {
	 emailext attachLog: true, 
		 body: "${currentBuild.result}: ${BUILD_URL}", 
		 compressLog: true, 
		 subject: "Build Notification: ${JOB_NAME}-Build# ${BUILD_NUMBER} ${currentBuild.result}", 
		 to: 'jakub.jurczak42@gmail.com'
		
    	}
    	
    	failure {
		emailext attachLog: true,
			body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}", 
			subject: ' Jenkins notification', 
			to: 'jakub.jurczak42@gmail.com'
    	}
    }
}
