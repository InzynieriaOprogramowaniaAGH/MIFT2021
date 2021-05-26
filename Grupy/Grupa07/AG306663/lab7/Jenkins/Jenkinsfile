pipeline{
	agent any
	tools {
	    nodejs "nodejs"
	}
  stages {
	  
	  stage('Build'){

            steps{
                echo "Building..."
		sh 'git pull origin master'
                sh 'npm install'
                }
	    post{
			always{
				echo 'Finished'
			}
			failure{
				messageFunction('BUILD', 'Failure')
			}
			success{
				messageFunction('BUILD', 'Success')
			}
		}
            }
     
      	stage('Test') {
			steps {
				echo 'Testing'
				sh 'npm run test'
			}
			post{
				always{
					echo 'Finished'
				}
				failure{
					messageFunction('TEST', 'Failure')
				}
				success{
					messageFunction('TEST', 'Success')
				}
			}
		}
	}
}

def messageFunction(stage, status) {
	echo status
	emailext attachLog: true,
		body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
		to: 'annagrzesiak04@gmail.com',
		subject: stage + " " + status
}
