pipeline{
    agent any

    tools { nodejs "nd" }
    
    stages{
        stage('Build'){
            steps{
                echo 'Building app...'
                sh 'npm install'
            }  
            post{
				failure{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: ${currentBuild.fullDisplayName}",
                        to: 'olakrason1999@gmail.com',
                        subject: "Jenkins build failed ${env.BUILD_NUMBER}"
				}
				success{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: ${currentBuild.fullDisplayName}",
                        to: 'olakrason1999@gmail.com',
                        subject: "Jenkins build succeed ${env.BUILD_NUMBER}"
				}
			}   
        } 
        stage('Test'){
            steps{
                echo 'Testing app...'
                sh 'npm run test' 
            }
            post{
				failure{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: ${currentBuild.fullDisplayName}",
                        to: 'olakrason1999@gmail.com',
                        subject: "Jenkins test failed ${env.BUILD_NUMBER}"
				}
				success{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: ${currentBuild.fullDisplayName}",
                        to: 'olakrason1999@gmail.com',
                        subject: "Jenkins test succeed ${env.BUILD_NUMBER}"
				}
			}
     
        }  
        stage('Deploy'){
			steps{
				echo 'Deploying...'
				sh 'docker build -t deploy -f Dockerfile .'
			}
			post{
				failure{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: ${currentBuild.fullDisplayName}",
                        to: 'olakrason1999@gmail.com',
                        subject: "Jenkins deploy failed ${env.BUILD_NUMBER}"
				}
				success{
					emailext attachLog: true,
						body: "${currentBuild.currentResult}: ${currentBuild.fullDisplayName}",
                        to: 'olakrason1999@gmail.com',
                        subject: "Jenkins deploy succeed ${env.BUILD_NUMBER}"
				}
			}
        }
    }
 }
   
