1. Pierwszym krokiem byla ionstalacja snapd oraz ngrok komendami:
    sudo apt install snapd
    sudo snap install ngrok
ngrok zapewnia bezpieczne tunelowanie do localhosta

2. Nastepnie uruchomienie go komenda: ngrok http 8080, wybranie portu na ktr jest jenkins

3. dodanie webhooka do gita podając adres z NGroka oraz dopisując /github-webhook/

4. rozszerzenie jenkinsfile'a o stage Deploy:
		stage('Deploy') {
			steps {
				echo 'Deploy'
				sh 'docker build -t deploy -f Dockerfile-Deploy .'
			}
			post  {
				always{
					echo 'Finished'
				}
				failure{
					messageFunction('DEPLOY', 'Failure')
				}
				success{
					messageFunction('DEPLOY', 'Success')
				}
            		}
		}

5. Deploy zostanie uruchomiony na dedykowany kontener dockerowy:
    sh 'docker build -t deploy -f Dockerfile-Deploy .'

6. stworzenie Dockerfile-Deploy oraz dodanie go do repo:
    FROM ubuntu:latest

    ENV TZ=Europe/Warsaw

    RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
    RUN apt-get -y update
    RUN apt-get install git -y
    RUN apt-get install npm -y

    COPY . Socket.io-Messenger/
    WORKDIR Socket.io-Messenger

na pinga oraz commita ngrok pokazuje: status 200
a na commita co da się sprawdzić w logach pokazany jest trigger: Started by GitHub push by WiktorLigeza zamiast Started by user admin