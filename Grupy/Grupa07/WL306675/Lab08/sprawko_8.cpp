Pipeline z poprzednich labów rozszerzono o:

1. W sekcji stage("Build"):
    - pobrana zostaje najnowsza wersja kodów źródłowych 
    - budowanie 
    - powiadomienie użytkownika z pomocą funkcji wysyłającej informacje na maila o sukcesie oraz porażce etapu tego stagea
    kod:
	  stage('Build'){

                steps{
                    echo "Building..."
                    sh 'git pull origin master' 
                    sh 'npm install'
                    }
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

2. następnie po poprawnym etapie budowania następuje etap testowy, również w tym przypadku użytkownik zostaje powiadomiony
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

3. funkcja messageFunction - zajmująca się wysyłaniem statusu na poczte:
    def messageFunction(stage, status) {
                                            echo status
                                            emailext attachLog: true,
                                                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}",
                                                to: 'wiktorligeza@gmail.com',
                                                subject: stage + " " + status
                                        }

4. hook("post-commit"):
     
   #!/bin/bash
    echo "To jest commit hook, który będzie kiedyś uruchamiał Pipeline po kązdym nowym commicie"
    exit 1