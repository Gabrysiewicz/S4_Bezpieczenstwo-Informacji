# Bezpieczeństwo informacji - Lab4
### P4.1.1 Zwróć uwagę na komunikaty na rys. Dlaczego tak się dzieje? 

Wszystkie klucze powinny skladac sie z 64 znakow, aby openssl enc nie zapelniaj ich zerami.
Taka operacja generowania klucza w ktorym sporym ciagem sa zera moze zle wplynac na bezpieczenstwo.

### P4.1.2 Czy wszystkie tryby wymagają wektora inicjalizującego? 
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

### P4.2.1 Zaszyfruj i odszyfruj plik stosując opcje -base64 i -salt. Opisz, co uzyskasz stosując te opcje. 

```    
 ======== Encrytption ======== 
openssl enc -aes-256-cbc -base64 -salt -in paranoid.txt -out paranoid_aes_salt.bin
enter aes-256-cbc encryption password:
Verifying - enter aes-256-cbc encryption password:
*** WARNING : deprecated key derivation used.
Using -iter or -pbkdf2 would be better.
```
```    
 ======== Decrytption ========
openssl enc -aes-256-cbc -d -base64 -salt -in paranoid_aes_salt.bin -out paranoid_salt.txt     
enter aes-256-cbc decryption password:
*** WARNING : deprecated key derivation used.
Using -iter or -pbkdf2 would be better.
```
```    
 ======== Encrypted ========
U2FsdGVkX1/9S9yEMBUzEHQ4U18fPIOVaJDnUSi2N2JbUYZvBGgTHWPFfnmCQiTM
xtdChPbxBq7hhJ8sag0nLydA3NeHjiseBwHAA709pxRcEW5FMwRagOnfYA95+2Gs
Z59qKrhhbZKgq8QFTdiZoVCzulV7PCqx+pa8qDxLdjaQh8S7UQbg0MklA8ZADPdo
U+6wgtEQygNqroc4R4H+zPrt3+6b+7z2uILpbyQiyNPKIoMhz6lG052kSKfgfvdM
GX9kmHBVRutfJYKY23F/hBaudQugwK7rA/2FaCIaE7Sa0hNJn+41SQPsq1lvXVnC
nmcTwpeIxasA48iK0Pifsby9W6/y3E2vGMzID1ZXmyQFdXqSw+u/nxwNRfnc/P0r
eIqWDR1ANSMJB0DuyBK6KNjZ//P60eCwuaD6L4jGF0+Fm2r5VNLlprisWcS9MDc0
UWV7Fj5a2BQ9aUH60KpYrSBZvspK5ypS6V0TOfyG/P+7o1Hp4FWghwRRofJIhtb1
cARMKfiPexF19pKaif1N9VBFLd+eTUNPJ77V30sTUu+mEIgXnu1wR4MXGpovol+E
mB/Ma83AwqHntPV6PHa6GMJIgPpZCDK6+m8Xrjvm+XLWFsKHfLTA+mDyOnkAvQc/
5XiwAFP8MEDt1mu4tkaUYi5uuLpuCar6dLTdc32tmZXwhopVUDZA1EO4UihxRo/g
PjHeBBJxRtD9w6KUcIDcm+NXJw6/Vs37mnqdHgROI0EQ0iItkxK8lP8mpz1V9JfS
UMqH0rQFjZ0zMAl+2OkFpSzTATkDTcmJGtYHmII+8kdbc5PskczaDy0F3fqt2czQ
i5Rzp5w/h0S7mjN3Pl/nZeiY6W4xKscWGCt3M2EIUmwMXt2Htqf4gyxHfMhDHe1F
```
```    
 ======== Decrypted ========
Finished with my woman 'cause
She couldn't help me with my mind
People think I'm insane because
I am frowning all the time
All day long I think of things
But nothing seems to satisfy
Think I'll lose my mind
If I don't find something to pacify
Can you help me
Occupy my brain?
Oh yeah
I need someone to show me
The things in life that I can't find
I can't see the things that make
True happiness, I must be blind
Make a joke and I will sigh
And you will laugh and I will cry
Happiness I cannot feel
And love to me is so unreal
And so as you hear these words
Telling you now of my state
I tell you to enjoy life
I wish I could but it's too late
```
Jaka opcja umożliwi podanie klucza szyfrującego w linii polecenia.
### P.4.3.1 Wyświetl zawartość zaszyfrowanych plików graficznych. Umieść je w sprawozdaniu.
Omów uzyskane wyniki. Uzasadnij zauważone charakterystyczne cechy
poszczególnych wyników w zależności od zawartości pliku graficznego. Czy we
wszystkich szyfrogramach są takie same i dlaczego? Przeanalizuj swoje obserwacje
i opisz je w sprawozdaniu.

### Szyfrowanie EBC nie nadaje się do obrazów prostch o małej złożoności kolorystycznej i geometrycznej


### P.4.4. Oznacz miejsce wprowadzenia przekłamania i zamieść tą informacje w sprawozdaniu.
Ile danych jestes w stanie odczytać po odszyfrowaniu uszkodzonych plików
zaszyfrowanych algorytmem szyfrującym pracującym w trybie ECB, CBC, CFB, OFB,
CTR? Opisz, jakiego algorytmu użyłeś. Wyjaśnij uzyskane wyniki. Wyciągnij wnioski
z przeprowadzonego badania i opisz je w sprawozdaniu?
```
➜  matrix head error_???_d.txt
==> error_cbc_d.txt <==
Wake up, Neo...
H/ou...�֠
Follo>y/� white rabbit.

Knock, knock, Neo

==> error_cfb_d.txt <==
Wake up, Neo...
The Matrix has you...
Follow the white rabbit.

Knoc�D��ock, Ne�#
==> error_ctr_d.txt <==
Wake up, Neo...
The Matrix has you����ollow the white rabbit.

Knock, knock, Neo

==> error_ecb_d.txt <==

==> error_ofb_d.txt <==
Wake up, Neo...
The Matrix has you...
Follow the white rabbit.

Knock, knock,N�|-% 
```
We Wszystkich plikach wprowadzałem 5 losowych znaków 1 obok drugiego w losowym miejscu. Wprowadzenie 'błędu' na początku sprawiał że hasło przesawało działać przez co nie dało się odszyfrować pliku np.error_ecb_d.txt 
