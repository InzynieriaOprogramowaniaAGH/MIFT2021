1. Zpullowałem zmiany na branchu Grupa02. Następnie utworzyłem swojego brancha na aktualne laboratoria za pomocą komendy `git checkout -b Grupa02-MA306420_Lab03`. Następnie zcherripickowałem z mastera commit z instrukcją na dzisiejsze laboratoria do swojego brancha, aby móc go wygodnie otworzyć na komputerze.
2. Skopiowałem plik `./.git/hooks/commit-msg` do `./Grupy/Grupa02/MA306420/Lab02/hooks`
3. Dockera miałem już zainstalowanego
4. Konto na dockerhubie też już posiadam
5. Utworzyłem plik Dockerfile, znajdujący się w folderze Lab03. Zawarłem w nim instrukcje instalacji gita, instlacji odpowiednich certyfikatów sieciowych (bez nich `git clone` zwracało błąd - rozwiązanie ze [stackoverflow](https://stackoverflow.com/questions/35821245/github-server-certificate-verification-failed)). Ostatnim krokiem zawartym w dockerfile jest sklonowanie repozytorium przedmiotu z githuba.
6. Zbudowałem obraz na podstawie utworzonego Dockerfile za pomocą komendy `docker build -t devops:1.0 .` . Po zbudowaniu obrazu stworzyłem na jego podstwie nowy kontener za pomocą polecenia `docker run --name devops_contener -it devops:1.0`. W kontenerze zweryfikowałem istnienie swojego brancha przez wywołanie komendy `git checkout Grupa02-MA306420_Lab02`