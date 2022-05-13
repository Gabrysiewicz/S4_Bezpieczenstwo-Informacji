<h1 align='center'>Skróty kryptograficzne</h1>

## Zadanie 5.1. Wykorzystanie algorytmów nieodwracalnej funkcji skrótu go generowania skrótu wiadomości
1. Utwórz trzy pliki: plik 900 B, plik 900 kB i 100 MB
2. Użyj polecenia openssl dgst do wygenerowania wartości funkcji skrótu dla
utworzonych plików.
```
➜  LAB6-Skroty openssl dgst -sha256 *         
SHA256(100MB.txt)= 0fe8db603465b14919fa748542f6c51e9c5cbdd07ae197fb75fd6fba8e7ceb52
SHA256(900B.txt)= 051233934020fc8ea0b3d3bf5fc1a4890efc2771598e29162e18d1c3a9c9169c
SHA256(900kB.txt)= 12230942a7ef8519225a47b7a61b3997b59cae29f62c7773342a20d0f3c81496
```
### P.5.1. Dla każdego z tych plików oblicz wartość funkcji skrótu za pomocą trzech wybranych algorytmów wykorzystując funkcjonalność openssl. Omów i porównaj otrzymane skróty wiadomości.

Określ średni czas przetworzenia 1MB danych dla każdej z kombinacji: rozmiar pliku –
algorytm obliczenia skrótu. W celu określenia czasu wykonania polecenia skorzystaj
z systemowego polecenia "time". Jako wynik zapisz sumy czasów user+sys. Wynik
należy zapisać, jako średnia z minimum 100 pomiarów. Otrzymane wyniki umieścić
w tabeli, a następnie sporządzić wykresy dla zastosowanych algorytmów.
| Algorytm | Plik | user+sys |
| --- | --- | --- |
| md5 | 900B | 0s |
| md5 | 900kB | 0.1s |
| md5 | 100MB | 0.21s |
| sha1 | 900B | 0s |
| sha1 | 900kB | 0.5s |
| sha1 | 100MB | 0.17s |
| sha256 | 900B | 0s |
| sha256 | 900kB | 0s |
| sha256 | 100MB | 0.32s |
| sha512 | 900B | 0s |
| sha512 | 900kB | 0.5s |
| sha512 | 100MB | 0.23s |
| whirlpool | 900B | 0s |
| whirlpool | 900kB | 0.5s |
| whirlpool | 100MB | 0.9s |
## Zadanie 5.2. Funkcje skrótu a bezpieczeństwo przechowywanych haseł
```
### Aktualne hasło: student
student:$6$Rn6W1v60Cpe4ctsL$x4bJ9vtmtwwZj4zYFJ7ZElc8rKR6CzJNfrHNy/zr1kEIX3T6B8k2if3qoXzegwGMn7GZXuMQ1AS1Tyb/uX9nE.:19124:0:99999:7:::
```
```
➜  LAB6-Skroty openssl passwd -6 -salt X5afde0 hiszpanskainkwizycja
$6$X5afde0$ypl4hiwv8gEL8upFl85bny4NadCSi3z0G3lXRfZsLS/gzFoD..lJL82AzdHoEj4DHgaVF4VOEknjTFV.pEOPu1
➜  LAB6-Skroty sudo usermod -p '$6$X5afde0$ypl4hiwv8gEL8upFl85bny4NadCSi3z0G3lXRfZsLS/gzFoD..lJL82AzdHoEj4DHgaVF4VOEknjTFV.pEOPu1' student
➜  LAB6-Skroty sudo grep student /etc/shadow
student:$6$X5afde0$ypl4hiwv8gEL8upFl85bny4NadCSi3z0G3lXRfZsLS/gzFoD..lJL82AzdHoEj4DHgaVF4VOEknjTFV.pEOPu1:19124:0:99999:7:::
➜  ~ su student
Hasło: (hiszpanskainkwizycja)
student@dell:/home/dell$ 
``` 
### P.5.3. Jakie zmiany zauważyłeś w pliku shadow? Zaloguj się na konta root lub student. Jakiego hasła użyłeś? Udokumentuj wykonanie ćwiczenia. Omów wykonane ćwiczenie i jego efekty. Czy dana metoda zmiany hasła jest bezpieczna? Jeśli nie zaproponuj zmiany i wyjaśnij dlaczego.

Hasło w postaci zahashowanej oraz jawnej jest widoczne na terminalu a co za tym idzie jest też widoczne w histori terminala oraz plikach ~/.(shell_name)_history
Można wymusić na użytkowniku zmiane hasła modyfikująć /etc/shadow aby użytkownik sam zmienił hasło przy najbliższym logowaniu

## Zadanie 5.3. Keyed Hash oraz HMAC

Treść zadania
- Utwórz plik o nazwie hmac o dowolnej wielkości.
- Należy wygenerować funkcję skrótu z kluczem dla pliku, wykorzystując algorytmy
HMAC-MD5, HMAC-SHA256 oraz HMAC-SHA1. Podczas zadania należy
wykorzystać klucze o trzech różnych długościach.
```
➜  LAB6-Skroty openssl dgst -md5 -hmac "Black" hmac 
HMAC-MD5(hmac)= 9aead12d19ba8ab8a95aca6e86799c74
➜  LAB6-Skroty openssl dgst -sha256 -hmac "Sabbath" hmac
HMAC-SHA256(hmac)= 74df578ff5c4f71a1ea643eb6728729009b73544ee5e5efc4c418d655f16315b
➜  LAB6-Skroty openssl dgst -sha1 -hmac "Paranoid" hmac
HMAC-SHA1(hmac)= 305f7a2c05c2e9cf7360f999b64e2cf70e43b8d1
```
- Przykład polecenia generuje wartość funkcji z kluczem wykorzystując algorytm
HMAC-MD5. Ciąg występujący po opcji -hmac jest kluczem. Zmodyfikuj polecenie
dla każdego z algorytmów.
```
openssl dgst -md5 -hmac "abcdefg" filename
```
### P.5.4. Czy w algorytmie HMAC konieczne jest używanie kluczy o stałej długości? 
 Nie jest to konieczne
### P.5.5. Jeśli tak, to, o jakiej długości? Odpowiedź uzasadnij w oparciu o wyniki przeprowadzonych testów.
klucze dla SHA-1 powinny być większe/równe 20 bajtów i nie większe niż 64
 ```
➜  LAB6-Skroty openssl dgst -sha1 -hmac "Paranoid" hmac
HMAC-SHA1(hmac)= 305f7a2c05c2e9cf7360f999b64e2cf70e43b8d1
➜  LAB6-Skroty openssl dgst -sha1 -hmac "Paranoidd" hmac
HMAC-SHA1(hmac)= c145c160f5eced89878b871a2e3b1a5e6babcf0d
➜  LAB6-Skroty openssl dgst -sha1 -hmac "Paranoia" hmac 
HMAC-SHA1(hmac)= d58a80fbd0c8446a061d16274a467113d0ef5988
➜  LAB6-Skroty openssl dgst -sha1 -hmac "Parano" hmac  
HMAC-SHA1(hmac)= 625dbd01569bb1250dc03c66e961e1dab0cd1d34
➜  LAB6-Skroty openssl dgst -sha1 -hmac "Paranoi" hmac
HMAC-SHA1(hmac)= adbd474d1280ed7c38057ee6cc67b3d84739aff1
 ```
 ### Zadanie 5.4. Losowość nieodwracalnej funkcji skrótu
Treść zadania
- Utwórz plik o nazwie testowy.txt o dowolnej wielkości.
- Wygeneruj wartość funkcji skrótu H1 dla tego pliku wykorzystując algorytmy MD5 i następnie SHA256.
- Zamień jeden bit na bit przeciwny w pliku wejściowym. Użyj w tym celu edytora Okteta.
- Wygeneruj wartość funkcji skrótu H2 dla zmodyfikowanego pliku

"bit przeciwny" - nie jestem pewien jak to rozumieć ale jako iż w pliku mamy znaki ASCII(0 do 127) a w systemie szesnastkowym liczby od 0 do 255
to chodzi o zamiane 0 -> 255, 1 -> 254, 2 -> 253... ale ze dla ASCII nie dokońca jest to możliwe więc zakładam że może chodzić o (szesnastkowe) 67 -> 76 : g -> v lub w ograniczeniu szesnastkowym do 127 (dziesiętnie): 0 -> 127, 1 -> 126, ... 70 -> 58 : F -> :

Wersja 67 -> 76 : g -> v
 ```
➜  LAB6-Skroty openssl dgst -md5 testowy.txt   
MD5(testowy.txt)= c54eef216987067168e0e9034fb8f23b
➜  LAB6-Skroty openssl dgst -sha256 testowy.txt
SHA256(testowy.txt)= 8cd1c7597e03af49969ef77190cbc8aa0c9f30e75f2d79fcba423b34d3a38de4
➜  LAB6-Skroty okteta testowy.txt       
➜  LAB6-Skroty openssl dgst -md5 testowy.txt   
MD5(testowy.txt)= dc43c964e028c01632e52f3836dfdd7c
➜  LAB6-Skroty openssl dgst -sha256 testowy.txt
SHA256(testowy.txt)= 13e2205488a3c7ecd382ebcdc564e1a7a06f92e77f5580a6980f03777e2aeb91
 ```
### P.5.6. Proszę przeanalizować otrzymane wyniki i odpowiedzieć w sprawozdaniu na pytanie czy H1 oraz H2 są podobne czy też nie. Odpowiedź należy uzasadnić.
Dla obu przypadków hashe były różne. Licząc "sumę" kontrolną prawdopodobiństwo otrzymania identycznych sum dla różnych plików jest bliskie zeru
### P.5.7. Proszę napisać program obliczający ile jest zgodnych bitów w H1 oraz H2

## Zadanie 5.5. Bezpieczeństwo funkcji skrótu
Treść zadania
- Pobierz archiwum o nazwie letters i następnie je rozpakuj.
- Otwórz i porównaj ze sobą dwa pliki znajdujące się w folderze po rozpakowaniu.
- Wygeneruj wartości funkcji skrótu z plików. Użyj algorytmu MD5. Porównaj otrzymane skróty.
```
➜  LAB6-Skroty openssl dgst -md5 *.ps
MD5(letter_of_rec.ps)= a25f7f0b29ee0b3968c860738533a4b9
MD5(order.ps)= a25f7f0b29ee0b3968c860738533a4b9
Hashe są identyczne
```
- Wygeneruj wartości funkcji skrótu z plików. Użyj algorytmu SHA256. Porównaj otrzymane skróty.
```
➜  LAB6-Skroty openssl dgst -sha256 *.ps
SHA256(letter_of_rec.ps)= de4e4c6e2b94e95a3c5bd72a9a6af29bc5f83bf759325d9921943a6fc08ea245
SHA256(order.ps)= 077046dd66015e05c3e03a43a6e4de129038e0701de5a4103fc7ed91c3782d06
Hashe są różne
```
### P.5.8. Czy pliki po rozpakowaniu się różnią? Zamieść odpowiednie zrzuty z wygenerowanymiwartościami funkcji skrótu. Omów czy otrzymane z plików wartości funkcji skrótu dla danych algorytmów są takie same czy różne? Omów wpływ stosowania algorytmów starszego typu na poziom bezpieczeństwa „haszowania”. Czy użyłbyś algorytmu MD5 do podpisywania plików? Odpowiedź uzasadnij.

Na bazie tych dwóch plików można stwierdzić że algorytm MD5 jest podatny na kolizje. Co za tym idzie można wygenerować różne pliki o identycznych sumach kontrolnych przez co MD5 okazuje się dość słabym algorytmem. Ze względów bezpieczeństwa lepiej było by użyć bardziej współczesnego algorytmu.
## Zadanie 5.6. Nieodwracalność kontra odporność na kolizje
