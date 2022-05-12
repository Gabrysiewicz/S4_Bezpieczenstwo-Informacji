# Skróty kryptograficzne
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
