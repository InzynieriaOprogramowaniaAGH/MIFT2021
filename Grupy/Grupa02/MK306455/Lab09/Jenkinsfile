pipeline {
    agent any
    environment{
    	build_success = true
    	credentials = 'dockerhub_id'
    	
    }
    stages {
        stage('Build') {
            steps {
                sh 'git checkout master'
                sh 'git pull'
                
                sh 'npm install'
                
            }
            post {
            	
            	failure{
            		script{
            			build_success = false
            			
            			echo 'Build failed....'
			    	emailext attachLog: true,
				body: "Build failed for job ${env.JOB_NAME}",
				subject: "Build failed.",
				to: 'marcin.kapusta2986@gmail.com'
            		}
            	}
            	success{
            		echo 'Build successful....'
			emailext attachLog: true,
			body: "Builds succeeded for job ${env.JOB_NAME}",
			subject: "Build sucessful.",
			to: 'marcin.kapusta2986@gmail.com'
            	}
            
            }
        }
        stage('Test') {
            steps {
            	script{
            		if(build_success)
            		{
				echo 'Testing..'
				
				sh 'npm test > tests_log.txt'
			}
                }
            }
            post {
            	
            	success{
            		echo 'Tests succeeded....'
			emailext attachLog: true,
			attachmentsPattern: 'tests_log.txt',
			body: "Tests successful for job ${env.JOB_NAME}",
			subject: "Tests successful.",
			to: 'marcin.kapusta2986@gmail.com'
            	}
            	failure{
            		echo 'Tests failed....'
			emailext attachLog: true,
			attachmentsPattern: 'tests_log.txt',
			body: "Tests failed for job ${env.JOB_NAME}",
			subject: "Tests failed.",
			to: 'marcin.kapusta2986@gmail.com'
            	}
            
            }
            
        }
        stage('Deploy') {
            steps {
            	script{
            	
		        sh 'docker build -t mkapust9/jenkins_deploy -f Deploy .'
		        docker.withRegistry('',credentials)
		        {
		        
		        	sh 'docker push mkapust9/jenkins_deploy'
		        }
                }
                
            }
            post {
            	
            	failure{	
            			
            		echo 'Deploy failed....'
			emailext attachLog: true,
			body: "Deploy failed for job ${env.JOB_NAME}",
			subject: "Deploy failed.",
			to: 'marcin.kapusta2986@gmail.com'
            		
            	}
            	success{
            		echo 'Deploy successful....'
			emailext attachLog: true,
			body: "Deploy succeeded for job ${env.JOB_NAME}",
			subject: "Deploy sucessful.",
			to: 'marcin.kapusta2986@gmail.com'
            	}
            
            }
        }
    }
}
