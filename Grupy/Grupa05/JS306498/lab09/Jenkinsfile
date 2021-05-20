pipeline {

    agent any
	tools {nodejs "NodeJS"}
    stages {
        stage('Build') {
            steps {
                echo 'Buid...'
                //checkout scm//
		sh 'npm install'
            }
            post {
        	failure {
            		emailext attachLog: true,
                	body: "${currentBuild.currentResult}:  build ${env.BUILD_NUMBER} Job ${env.JOB_NAME}",
                	to: 'sosinkuba99@gmail.com',
                	subject: "Build result - fail"
        	}
        	success {
            		emailext attachLog: true,
                	body: "${currentBuild.currentResult}:  build ${env.BUILD_NUMBER} Job ${env.JOB_NAME}",
                	to: 'sosinkuba99@gmail.com',
                	subject: "Build result - success"
        	}
    		}
        }
        
        
        
        stage('Test') {
            steps {
               echo 'Test...'
                sh 'npm run test'
            }
    post {
    
    	always {
    	    echo 'End'
    	}
    	
    	success {
	emailext attachLog: true,
                body: "${currentBuild.currentResult}:  build ${env.BUILD_NUMBER} Job ${env.JOB_NAME}",
                to: 'sosinkuba99@gmail.com',
                subject: "Test result- success"
    	}
    	
        failure {
            echo 'Failure'
            emailext attachLog: true,
                body: "${currentBuild.currentResult}:  build ${env.BUILD_NUMBER} Job ${env.JOB_NAME}",
                to: 'sosinkuba99@gmail.com',
                subject: "Test result- failed"
        }
    }
}
	    
	    stage('Deploy') {
            steps {
                echo 'Deploying...'
                sh 'docker build -t deploy -f Dockerfile.deploy .'
                
	    }
            post {
                success {
                   echo 'Success'
		emailext attachLog: true,
                body: "${currentBuild.currentResult}:  build ${env.BUILD_NUMBER} Job ${env.JOB_NAME}",
                to: 'sosinkuba99@gmail.com',
                subject: "Deploy result- success"
                }
        
                failure {
                    echo 'Failure'
            	emailext attachLog: true,
                body: "${currentBuild.currentResult}:  build ${env.BUILD_NUMBER} Job ${env.JOB_NAME}",
                to: 'sosinkuba99@gmail.com',
                subject: "Deploy result- failed"
                }
            }
        }
	    
	    
}
}
