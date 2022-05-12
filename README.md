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
