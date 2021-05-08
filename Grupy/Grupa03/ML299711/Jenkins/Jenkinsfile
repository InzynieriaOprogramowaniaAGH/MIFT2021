pipeline{
	agent any
	stages {
		stage('Build') {
			steps{
				echo 'Building'
				sh 'git pull origin master'
				sh 'npm install'
				sh 'npm run build'    
			}			
			post{
				always{
					echo 'Finished'
				}
				failure{
					statusAllert('Build', 'Failure')
				}
				success{
					statusAllert('Build', 'Success')
				}
			}
		}

		stage('Test'){
			when {
				expression {currentBuild.result == 'SUCCESS' }
			}

			steps{
				echo 'Testing'
				sh 'npm run test'
			}   


			post{
				always{
					echo 'Finished'
				}
				failure{
					statusAllert('Test', 'Failure')
				}
				success{
					statusAllert('Test', 'Success')
				}
			}
		}      
	}	
}

def statusAllert(stage, status) {
echo status
emailext attachLog: true,
body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
to: 'olekn41@gmail.com',
subject: stage + status
}
