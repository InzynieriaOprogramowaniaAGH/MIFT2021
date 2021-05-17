pipeline {
    agent any
        tools {nodejs "NodeJS"}
    stages {
	stage('Build') {
	    steps {
	       echo 'Building!'
	       sh 'npm install'
	       
	    }
	post {
                success {
                  emailext attachLog: true,
                      body: "Build OK",
                      to: 'mateo7413@gmail.com', 
                      subject: "Build  succeed!! "
               }
               failure {
                  emailext attachLog: true,
                      body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                      to: 'mateo7413@gmail.com', 
                      subject: "Build failed!!"
               }    
           }
        }            
	stage('Test') {
	    when {
	       expression {
	          currentBuild.currentResult == null || currentBuild.currentResult == 'SUCCESS'
	          }
	       }
	    steps {
	       echo 'Testing!'
	       sh 'npm run test'
	       
	    }
            post {
                success {
                  emailext attachLog: true,
                      body: "Test OK",
                      to: 'mateo7413@gmail.com', 
                      subject: "Test succeed!! "
               }
               failure {
                  emailext attachLog: true,
                      body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                      to: 'mateo7413@gmail.com', 
                      subject: "Test failed!!"
               }    
           }           
	}
	stage('Deploy') {
	    when {
	       expression {
	          currentBuild.currentResult == null || currentBuild.currentResult == 'SUCCESS'
	          }
	       }
	    steps {
	       echo 'Deploy!'
	       sh 'docker build -t app-chat -f Dockerfile_app .'
	       
	    }
	post {
                success {
                  emailext attachLog: true,
                      body: "Deploy OK. Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                      to: 'mateo7413@gmail.com', 
                      subject: "Deploy succeed!! "
               }
               failure {
                  emailext attachLog: true,
                      body: "Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}: ${currentBuild.currentResult}",
                      to: 'mateo7413@gmail.com', 
                      subject: "Deploy failed!!"
               }    
           }         
	}
    }
    
}
