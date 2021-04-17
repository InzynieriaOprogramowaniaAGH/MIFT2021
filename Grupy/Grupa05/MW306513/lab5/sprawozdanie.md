# 1. Utworzenie kontenera z jenkinsem
![](1docker-container.png)
# 2
Odpalenie kontera 
sudo docker run -p 8080:8080 -p 50000:50000 -d -v jenkins_home:/var/jenkins_home jenkins/jenkins:lts-jdk11
1 port to port dla Jenkinsa 
2 dla komunikacji typu Master / Slave
-d detached mode zebym dalej mogl sobie pisac w tej samej konsoli
-v tworze w kontenerze docker volume dla folderu jenkins_home przy okazji dzieki temu nie mam problemow z dostepem 

nastepnie zczytalem haslo z logow do zainicjalizowania jenkinsa
![](instalacja-jenkinsa-haslo-z-logow.png)
INSTALOWANIE 
![](instalacja.png)

![](admin-user-haslo1234).png)

Utworzylem nowe zadanie
![](new-jenkins-job.png)
Uruchomienie pipelina w poszukiwaniu Jenkinsfile 
![](logs.png)

# 3
Wrzucanie na docker huba
![](task3.png)

Pierwszy push byl bez taga dlatego sa dwa
![](docker-hub.png)
