1. Dodanie kluczy SSH do połączenia zamiast HTTPS

1.1. Tworzenie pary kluczy (publicznego i prywatnego) z wykorzystnaiem Ed25519 (opartego na krzywej eliptycznej Curve25519; o rozmiarze klucza 256 bitów i oferujący 128-bitowy poziom bezpieczeństwa z zastosowaniem podanych parametrów); zabezpieczenie klucza prywatnego frazą hasłową.

1.2. Zapisanie plików kluczy.

1.3. Załadnie kluczy do agenta SSH. (polecenia `eval "$(ssh-agent -s)"; ssh-add -k ~/.ssh/id_ed25519`)

1.4. Zarejestrwowanie kluczy po stronie serwera poprzez stronę ustawień interfejsu webowego github.com 

1.5 Poinformowanie klienta git o zmianie sposobu logowania:
git remote -v

2. Nadanie taga do aktualnych commitów:

3. Uporządkowanie branchy i folderów, pogruopowanie w grupy i foldery laboratoryjne przy pomocy polecenia `git mv`, aby zachować historię wykonanej zmiany.

4. Przygotowanie git hooka do weryfikacji nazw commitów.

5. Ostateczne dołączenie zmian wraz ze sprawozdaniem i wykonanie pull requesta z poziomu interfejsu webowego github.com

---

Wykorzystane komendy:
```
git pull origin
ssh-keygen -t ed25519 -C "szumilas.jakub@gmail.com"
eval "$(ssh-agent -s)"
ssh-add -k ~/.ssh/id_ed25519
git remote -v
git remote set-url origin git@github.com:InzynieriaOprogramowaniaAGH/MIFT2021.git
git tag -a JS283683_Lab02 -m "jakszu, owszem, także wszystko działa, poprosze to 10/10"
git push --follow-tags
```
---

Kod git hooka:
```
#!/bin/bash
required_id='JS283683*'
if ! grep -iqE "$required_id" "$1"; then
	echo "[git hook] Commit-msg format validation: FAILURE. [initials+student ID] required."
	exit 1;
fi
echo "[git hook] Commit-msg format validation: SUCCESS"
exit 0;
```