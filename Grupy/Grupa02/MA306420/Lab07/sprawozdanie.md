1. Sforkowałem repozytorium z używaną przeze mnie aplikacją chatu ([fork](https://github.com/maciejewiczow/feathers-chat))
1. Stworzyłem dwa dockerfile, jeden budujący aplikację (build.Dockerfile), a drugi przygotowujący aplikację do wdrożenia (run.Dockerfile).
   Obydwa umieściłem na sforkowanym repozytorium z chatem. Kopie każdego z nich umieściłem również w repozytorium przedmiotu.
1. Stworzyłem jenkinsfile definiujące pipeline, który buduje obraz dockerowy za pomocą dockerfile a następnie uruchamia dwa kontenery za pomocą docker-compose. Jeden z tych kontenerów uruchamia testy projektu, a drugi eslinta. Na końcu pipeline wysyła email do użytkownika uruchamiającego dany build, w którym zawiadamia o sukcesie lub porażce przebiegu i w razie porażki dołącza logi z pipeline
1. W interfejsie jenkinsa skonfigurowałem rozszerzenie do powiadomień email, aby używało założonego w tym celu konta gmail do wysyłania powiadomień o statusach pipeline
1. Stworzyłem nowy pipeline, który bazował na jenkinsfile pobieranym z forka chatu
