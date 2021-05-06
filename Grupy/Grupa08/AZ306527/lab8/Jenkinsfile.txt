pipeline {
    agent any
    stages {
        stage('Build'){
                agent {
                    docker { image 'node:alpine'
                      }
                 }
            steps{
		sh 'docker-compose up'

            }
	}
	stage('Test'){
	    steps{
                sh 'code/wait.sh server:1234 -- echo READY && node code/client.js'
	    }
 	}
    }
    post {
    failure {
        mail to: 'emroz@student.agh.edu.pl',
             subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
             body: "Something is wrong with ${env.BUILD_URL}"
    }
    success {
            echo 'I succeeded :D'
    }
}
}