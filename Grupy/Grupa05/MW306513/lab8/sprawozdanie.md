# 1, 2, 3
Stage 'Build' byl juz gotowy na poprzednich labolatoriach w celu 
odpalenia testow zeby przeszly

![img.png](img.png)

wszytko co znajduje sie w script jest dodane tylko 
po to zeby przetestowac
w jak najlatwiejszy sposob co sie dzieje w pipelinie jak 
stage 'Build' nie przejdzie.
Dlatego tez dodalem warunek w stage 'Test'<br>
![img_1.png](img_1.png)<br>
pipeline jest automatycznie przerywany<br> 
![img_2.png](img_2.png)<br>
logi z stage 'Test'<br>
![img_3.png](img_3.png)<br>
pojawia sie dokladnie ta sama wiadomosc, ktora dalem w Jenkinsfile<br>

Efekt po wykomentowaniu tego "zaklamania rzeczywistosci"<br>
![img_5.png](img_5.png)<br>
# 4
Dodalem post-commita do repo z komunikatorem<br>
![img_4.png](img_4.png)