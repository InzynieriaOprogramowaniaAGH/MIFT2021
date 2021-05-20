	pipeline {
	 agent any
	tools {
		nodejs "node"
	}
    stages {
	stage('Install dependencies') {
            steps {
                echo 'Installing dependencies..'
		    	sh 'apt install git -y'
            }
	  }
	  
	stage('Build') {
	  steps {
                echo 'Building..'
		  	git 'https://github.com/Whitiee/node-chat-app.git'
		        sh 'npm install'
            }
        }   
	  
	stage('Test') {
	  when {
		expression {currentBuild.result == null || currentBuild.result == 'SUCCESS'}
	  }
            steps {
                echo 'Testing..'
		        sh 'npm run test'
            }
        } 
        
        stage('Deploy') {
                echo 'Deploying..'
		        sh 'docker build -t deploy -f Dockerfile-deploy .'
            }
        } 
    }
    
    post {
        always {
            echo 'I have finished'
        }
        success {
            echo 'I succeeded!'
        }
        failure {
            echo 'I failed :('
            emailext attachLog: true, 
            	     body: "Something is wrong with ${env.BUILD_URL}",
            	     subject: "Failed test Pipeline: ${currentBuild.fullDisplayName}",
            	     to: 'juliafajer69@gmail.com'
        }
    }
}
