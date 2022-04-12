# Bezpieczeństwo informacji - Lab4
### P4.1. Zwróć uwagę na komunikaty na rys. Dlaczego tak się dzieje? 

Wszystkie klucze powinny skladac sie z 64 znakow, aby openssl enc nie zapelniaj ich zerami.
Taka operacja generowania klucza w ktorym sporym ciagem sa zera moze zle wplynac na bezpieczenstwo.

### P4.2 Czy wszystkie tryby wymagają wektora inicjalizującego? 
Nie wszystkie np.aes_256_ecb nie korzysta z wektora.
```
student@localhost:~/Paranoid> openssl enc -aes-256-ecb -e -in file -out file_aes_256_ecb.bin -iv "2020" 
enter aes-256-ecb encryption password:
Verifying - enter aes-256-ecb encryption password:
*** WARNING : deprecated key derivation used.
Using -iter or -pbkdf2 would be better.
warning: iv not used by this cipher
```
Udokumentuj w sprawozdaniu szyfrowanie i deszyfrowanie pliku przy użyciu wybranych algorytmów szyfrujących i trybów pracy.

