pipeline {
    agent any
        tools {nodejs "NodeJS"}
    stages {
	stage('Build') {
	    steps {
	       echo 'Run building...'
	       sh 'npm install'
	       
	    }
	}   
	stage('Test') {
	    when {
	       expression {
	          currentBuild.currentResult == null || currentBuild.currentResult == 'SUCCESS'
	          }
	       }
	    steps {
	       echo 'Run testing...'
	       sh 'npm run test'
	       
	    }
	}
    }
    post {
      always {
         echo 'Finish'
      }
      success {
         echo 'Everything OK'
         emailext attachLog: true,
             body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
             to: 'mateo7413@gmail.com', 
             subject: "Jenkinsfile build and test succeed!! "
      }
      failure {
          emailext attachLog: true,
             body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
             to: 'mateo7413@gmail.com', 
             subject: "Jenkinsfile failed!!"
      }    
    }           
}
