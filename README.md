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
P.5.1. Dla każdego z tych plików oblicz wartość funkcji skrótu za pomocą trzech wybranych
algorytmów wykorzystując funkcjonalność openssl. Omów i porównaj otrzymane
skróty wiadomości.
Określ średni czas przetworzenia 1MB danych dla każdej z kombinacji: rozmiar pliku –
algorytm obliczenia skrótu. W celu określenia czasu wykonania polecenia skorzystaj
z systemowego polecenia "time". Jako wynik zapisz sumy czasów user+sys. Wynik
należy zapisać, jako średnia z minimum 100 pomiarów. Otrzymane wyniki umieścić
w tabeli, a następnie sporządzić wykresy dla zastosowanych algorytmów. Przykładowe
polecenie do wykonania 100 pomiarów.
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
student@dell-Inspiron-5737:/home/dell$ 
```
P.5.3. Jakie zmiany zauważyłeś w pliku shadow? Zaloguj się na konta root lub student. Jakiego
hasła użyłeś? Udokumentuj wykonanie ćwiczenia. Omów wykonane ćwiczenie i jego
efekty. Czy dana metoda zmiany hasła jest bezpieczna? Jeśli nie zaproponuj zmiany
i wyjaśnij dlaczego.

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
