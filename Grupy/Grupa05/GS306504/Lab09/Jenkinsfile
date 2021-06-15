pipeline {

  agent {
    docker {
      image 'node:latest' 
      args '-p 3000:3000' 
    }
  }
  
  environment {
    CI = 'true' 
  }

  stages {
    stage('Build') {
      steps {
        sh "npm install"
      }
      post {
        success {
          echo 'Build success!'
          slackSend (color: '#00FF00', message: "Build success: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        }
        failure {
          echo 'Build failure!'
          slackSend (color: '#FF0000', message: "Build failure: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        }
      } 
    }

    stage('Test') {
      steps {
        sh 'npm test'
      }  
      post {
        success {
          echo 'Tests passed!'
          slackSend (color: '#00FF00', message: "Tests passed: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        }
        failure {
          echo 'Tests failure!'
          slackSend (color: '#FF0000', message: "Tests failed: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        }
      }
    }

    stage('Deploy') { 
            steps {
              echo 'Deploying!'
              sh 'docker build -t deploy -f Dockerfile-deploy .'
            }
            post {
        	failure {
        		echo 'Deployment failure'
            slackSend (color: '#00FF00', message: "Deployment failure: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        	}
        	success {
            echo 'Deployment succesful!'
            slackSend (color: '#00FF00', message: "Deployment sucesful: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})")
        	}
    		}
        }

  }
}