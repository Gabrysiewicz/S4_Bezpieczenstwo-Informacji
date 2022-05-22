<h1 align='center'>SSL</h1>

## Zadanie 6.1. Utworzenie głównego urzędu certyfikacji CA

```
➜  server openssl ecparam -out ca.key -name prime256v1 -genkey
```
```
➜  server openssl req -new -sha256 -key ca.key -out ca.csr
You are about to be asked to enter information that will be incorporated
into your certificate request.
What you are about to enter is what is called a Distinguished Name or a DN.
There are quite a few fields but you can leave some blank
For some fields there will be a default value,
If you enter '.', the field will be left blank.
-----
Country Name (2 letter code) [AU]:PL
State or Province Name (full name) [Some-State]:Lubleskie
Locality Name (eg, city) []:Lublin
Organization Name (eg, company) [Internet Widgits Pty Ltd]:Polibuda
Organizational Unit Name (eg, section) []:Polibuda
Common Name (e.g. server FQDN or YOUR name) []:Polibuda
Email Address []:Poli@bu.da

Please enter the following 'extra' attributes
to be sent with your certificate request
A challenge password []:Polibuda
An optional company name []:Polibuda
```
```
➜  server openssl x509 -req -sha256 -days 365 -in ca.csr -signkey ca.key -out ca.crt
Signature ok
subject=C = PL, ST = Lubleskie, L = Lublin, O = Polibuda, OU = Polibuda, CN = Polibuda, emailAddress = Poli@bu.da
Getting Private key
```
```
➜  server openssl req -noout -text -in ca.csr 
Certificate Request:
    Data:
        Version: 1 (0x0)
        Subject: C = PL, ST = Lubleskie, L = Lublin, O = Polibuda, OU = Polibuda, CN = Polibuda, emailAddress = Poli@bu.da
        Subject Public Key Info:
            Public Key Algorithm: id-ecPublicKey
                Public-Key: (256 bit)
                pub:
                    04:39:a1:dc:87:56:1b:5e:32:91:e3:bc:7f:d5:ab:
                    68:fa:67:5f:63:24:00:00:88:60:c3:81:ee:79:62:
                    05:94:16:be:cf:3f:3f:57:b2:c2:e6:22:d8:52:9c:
                    af:01:7e:1b:40:ff:65:71:ce:d4:e8:b8:a2:d5:85:
                    d3:c8:1c:a2:79
                ASN1 OID: prime256v1
                NIST CURVE: P-256
        Attributes:
            unstructuredName         :Polibuda
            challengePassword        :Polibuda
    Signature Algorithm: ecdsa-with-SHA256
         30:46:02:21:00:88:63:4f:33:fd:af:b1:df:12:6d:ba:07:7b:
         1b:6d:84:11:b8:96:48:44:33:0f:8b:e0:30:a1:f0:a1:83:50:
         4c:02:21:00:d8:3b:b8:41:0b:88:eb:ca:2f:ae:8a:56:5c:37:
         98:ca:80:32:e8:fa:9d:23:c2:00:9f:6c:fb:3b:67:53:40:29
```
## Zadanie 6.2. Utworzenie certyfikatu dla organizacji
```
➜  server openssl ecparam -out server.key -name prime256v1 -genkey
➜  server openssl req -new -sha256 -key server.key -out server.csr 
You are about to be asked to enter information that will be incorporated
into your certificate request.
What you are about to enter is what is called a Distinguished Name or a DN.
There are quite a few fields but you can leave some blank
For some fields there will be a default value,
If you enter '.', the field will be left blank.
-----
Country Name (2 letter code) [AU]:PL
State or Province Name (full name) [Some-State]:Lubelskie
Locality Name (eg, city) []:Lublin
Organization Name (eg, company) [Internet Widgits Pty Ltd]:Polibuda
Organizational Unit Name (eg, section) []:Polibuda
Common Name (e.g. server FQDN or YOUR name) []:Polibuda
Email Address []:Poli@bu.da

Please enter the following 'extra' attributes
to be sent with your certificate request
A challenge password []:Polibuda
An optional company name []:Polibuda
```
```
➜  server openssl x509 -req -in server.csr -CA ca.crt -CAkey ca.key -CAcreateserial -out server.crt -days 365 -sha256 
Signature ok
subject=C = PL, ST = Lubelskie, L = Lublin, O = Polibuda, OU = Polibuda, CN = Polibuda, emailAddress = Poli@bu.da
Getting CA Private Key
```
```
➜  server openssl x509 -in server.crt -text -noout
Certificate:
    Data:
        Version: 1 (0x0)
        Serial Number:
            4e:00:d7:fe:36:53:22:48:55:c2:73:25:a0:28:a5:45:64:79:50:66
        Signature Algorithm: ecdsa-with-SHA256
        Issuer: C = PL, ST = Lubleskie, L = Lublin, O = Polibuda, OU = Polibuda, CN = Polibuda, emailAddress = Poli@bu.da
        Validity
            Not Before: May 22 16:11:00 2022 GMT
            Not After : May 22 16:11:00 2023 GMT
        Subject: C = PL, ST = Lubelskie, L = Lublin, O = Polibuda, OU = Polibuda, CN = Polibuda, emailAddress = Poli@bu.da
        Subject Public Key Info:
            Public Key Algorithm: id-ecPublicKey
                Public-Key: (256 bit)
                pub:
                    04:48:30:d6:2d:55:4b:8c:42:3f:86:b9:8e:1a:90:
                    e1:3e:bd:a4:b8:3e:6b:0e:1e:63:3f:5f:ed:06:a8:
                    7c:e6:5c:94:4d:07:cb:78:10:80:35:e2:5a:f7:b6:
                    48:b3:f9:65:ac:13:98:79:42:a4:a9:67:4f:3c:8f:
                    dc:7f:5e:8b:56
                ASN1 OID: prime256v1
                NIST CURVE: P-256
    Signature Algorithm: ecdsa-with-SHA256
         30:46:02:21:00:d9:d4:d9:5e:38:62:29:60:ac:99:d7:d0:9c:
         c8:d5:d7:6c:91:48:21:b6:6e:01:61:f0:b7:d9:d9:97:e8:4f:
         66:02:21:00:db:de:88:8d:73:80:05:14:09:fe:91:60:4b:28:
         55:64:ed:87:b9:e3:38:46:b0:58:f6:fe:f9:5b:ce:fb:55:c4
```

### Zadanie 6.3. Zastosowanie infrastruktury klucza publicznego do stron WWW

```
➜  server sudo nano /etc/hosts
➜  server cp server.key server.pem
➜  server cat server.crt >> server.pem 
➜  server openssl s_server -cert server.pem -www
Using default temp DH parameters
ACCEPT
```
## P.6.1. Opisz i wyjaśnij swoje obserwacje. Co się stało i dlaczego?
Przeglądarka przyjeła wygenerowany cerfyfikat ale go nie rozpoznała.
Stało się tak ponieważ certyfikat był poprawny ale twórcy przeglądarki zapewne ze względów bezpieczeństwa korzystają tylko z kilku głównych/największych TTS'ów a nasz certyfikat nie ma autoryzacji z ich strony dlatego mimo zatwierdzenia certyfikaty przeglądara zamieszcza notę że nie rozpoznaje owego certyfikatu

## P.6.2. Wygeneruj i certyfikuj certyfikat dla serwera bi.cs.pollub.pl. W sprawozdaniu zamieść użyte polecenia oraz zrzut ekranu prezentujący odpowiedź uruchomionego serwera w przeglądarce
Postąpiłem identycznie do poprzednich zadań tyle że plik csr wystylizowałem na zgodny z bi.cs.pollub.pl
```
➜  cspollubpl openssl x509 -in pollub.crt -text -noout 
Certificate:
    Data:
        Version: 1 (0x0)
        Serial Number:
            6e:a2:45:7c:73:26:98:32:56:d8:bd:12:68:09:6a:89:64:7c:3f:bf
        Signature Algorithm: ecdsa-with-SHA256
        Issuer: C = PL, ST = Lubelskie, L = Lublin, O = Politechnika Lubelska, OU = WEII, CN = bi.cs.pollub.pl, emailAddress = pollub.pl
        Validity
            Not Before: May 22 17:05:35 2022 GMT
            Not After : May 22 17:05:35 2023 GMT
        Subject: C = PL, ST = Lubleskie, L = Lublin, O = Politechnika Lubelska, OU = WEII, CN = bi.cs.pollub.pl, emailAddress = pollub.pl
        Subject Public Key Info:
            Public Key Algorithm: id-ecPublicKey
                Public-Key: (256 bit)
                pub:
                    04:ce:2a:5b:ff:1f:e3:51:7e:05:eb:7b:50:e2:8d:
                    9d:46:73:2e:41:e6:5d:4f:fe:ec:8e:18:c0:03:c3:
                    b8:0f:00:9f:5c:90:53:92:d0:03:d1:43:8b:97:2a:
                    2d:80:85:9c:35:a5:b8:dc:8b:1a:6f:61:c7:72:03:
                    4f:ea:68:b5:ab
                ASN1 OID: prime256v1
                NIST CURVE: P-256
    Signature Algorithm: ecdsa-with-SHA256
         30:46:02:21:00:fa:6e:44:05:86:fd:13:c5:93:f8:d1:47:e5:
         73:9c:4f:94:43:29:99:60:7d:b6:30:14:a5:d5:40:d4:9e:cb:
         48:02:21:00:80:bd:0c:bb:12:05:0c:88:b1:17:1b:e0:0c:3c:
         fa:f8:a6:35:59:ad:08:21:58:76:7b:a9:b8:3b:f7:1a:6c:23
```
File: /etc/hosts
```
➜  cspollubpl cat /etc/hosts
127.0.0.1	localhost
127.0.0.1       mx
127.0.0.1	pkilab.com
127.0.0.1	Polibuda.com
127.0.0.1	Polibuda
127.0.0.1	bi.cs.pollub.pl
# The following lines are desirable for IPv6 capable hosts
::1		localhost ip6-localhost ip6-loopback
fe00::0		ip6-localnet
ff00::0		ip6-mcastprefix
ff02::1		ip6-allnodes
ff02::2		ip6-allrouters
```
Server: run
```
cspollubpl openssl s_server -cert pollub.pem -www
Using default temp DH parameters
ACCEPT
```
ZDJ

## P.6.3. Określ, z jakich elementów składa sie plik certyfikatu (*.pem) i jak wpływa modyfikacja bitów w poszczególnych elementach tegoż pliku na działanie serwera. Zmodyfikuj pojedyńczy bit w pliku server.pem przy użyciu edytora Hex. Uruchom ponownie serwer i przeładuj zawartość udostępnianej przez niego strony. Wyniki zamieść w tabeli zawierającej trzy kolumny: element pliku pem, opis elementu, opis wpływu modyfikacji bitu w tym elemencie na działanie serwera.
```
➜  cspollubpl cat pollub.pem 
-----BEGIN EC PARAMETERS-----
BggqhkjOPQMBBw==
-----END EC PARAMETERS-----
-----BEGIN EC PRIVATE KEY-----
MHcCAQEEIMUcLKi/bp1DP+ZGL7PJkpdc6kUL7CXF4PymC2lVaXhnoAoGCCqGSM49
AwEHoUQDQgAEzipb/x/jUX4F63tQ4o2dRnMuQeZdT/7sjhjAA8O4DwCfXJBTktAD
0UOLlyotgIWcNaW43Isab2HHcgNP6mi1qw==
-----END EC PRIVATE KEY-----
-----BEGIN CERTIFICATE-----
MIICKDCCAc0CFG6iRXxzJpgyVti9EmgJaolkfD+/MAoGCCqGSM49BAMCMIGVMQsw
CQYDVQQGEwJQTDESMBAGA1UECAwJTHViZWxza2llMQ8wDQYDVQQHDAZMdWJsaW4x
HjAcBgNVBAoMFVBvbGl0ZWNobmlrYSBMdWJlbHNrYTENMAsGA1UECwwEV0VJSTEY
MBYGA1UEAwwPYmkuY3MucG9sbHViLnBsMRgwFgYJKoZIhvcNAQkBFglwb2xsdWIu
cGwwHhcNMjIwNTIyMTcwNTM1WhcNMjMwNTIyMTcwNTM1WjCBlTELMAkGA1UEBhMC
UEwxEjAQBgNVBAgMCUx1Ymxlc2tpZTEPMA0GA1UEBwwGTHVibGluMR4wHAYDVQQK
DBVQb2xpdGVjaG5pa2EgTHViZWxza2ExDTALBgNVBAsMBFdFSUkxGDAWBgNVBAMM
D2JpLmNzLnBvbGx1Yi5wbDEYMBYGCSqGSIb3DQEJARYJcG9sbHViLnBsMFkwEwYH
KoZIzj0CAQYIKoZIzj0DAQcDQgAEzipb/x/jUX4F63tQ4o2dRnMuQeZdT/7sjhjA
A8O4DwCfXJBTktAD0UOLlyotgIWcNaW43Isab2HHcgNP6mi1qzAKBggqhkjOPQQD
AgNJADBGAiEA+m5EBYb9E8WT+NFH5XOcT5RDKZlgfbYwFKXVQNSey0gCIQCAvQy7
EgUMiLEXG+AMPPr4pjVZrQghWHZ7qbg79xpsIw==
-----END CERTIFICATE-----
```
| Część | Opis | Efekt |
| --- | --- | --- |
| EC Parameters | Opis | unable to load server certificate private key file |
| EC PRIVATE KEY | Opis | unable to load server certificate private key file |
| CERTIFICATE | Opis | unable to load certificate |

### P.6.4. Przywróć poprawną postać certyfikatu serwera, uruchom ponownie serwer, a następnie wyświetl stronę WWW korzystając z adresu https://localhost:4433. Jaki jest efekt? Wyjaśnij, co sie stało. 

Certyfikat wystawiony na bi.cs.pollub.pl nie obowiązuje dla localhost 
Serwer informuje o 'alert bad certificate' i alert number 42
Natomiast przeglądarka o tym że wystawiony certyfikat nie jest właściwy dla localhost:4433

### P.6.5. W celu określenia czasu szyfrowania i deszyfrowania skorzystaj z systemowego polecenia "time". Jako wynik zapisz sumy czasów user+sys. W celu zminimalizowania błędów napisz skrypt realizujący 100 powtórzeń dla każdej operacji mierząc w ten sposób czas jej wielokrotnego wykonania, następnie podaj wyniki średnie dla każdej operacji. Przedstaw je w postaci umożliwiającej porównanie wydajności np. obliczając ilość danych przetwarzanych w ciągu jednej sekundy. Opracuj zestawienie uzyskanych wyników w formie tabeli. Sporządź wykresy dla uzyskanych wyników.

| File | Mode | Time (s) |
| --- | --- | --- |
| 10B | Encryption | 0 |
| 200B | Encryption | 0 |
| 10M | Encryption | 0.05 |
| 10B | Decryption | 0 |
| 200B | Decryption | 0 |
| 10M | Decryption | 0.05 |

### P.6.6. Przedstaw wyniki analogicznie do tych z P. 6.5. Porównaj je ze sobą i skomentuj.

### Średni czas : 3s
| Type | 16 Bytes | 16 Bytes | 16 Bytes | 16 Bytes | 16 Bytes | 16 Bytes |
| --- | --- | --- | --- | --- | --- | --- |
| aes-128 cbc | 170570.46k | 169502.59k | 190912.52k | 180504.83k | 180095.83k | 181966.51k |
| aes-192 cbc | 161515.27k | 154438.57k | 154994.00k | 155213.59k | 155408.37k | 155096.29k |
| aes-256 cbc | 129349.68k | 150198.20k | 132249.08k | 135711.17k | 137189.80k | 136026.08k |

### Średni czas : 10s
|  |  | sign | verify | sign/s | verify/s |
| --- | --- | --- | --- | --- | --- |
| rsa | 512 bits | 0.000059s | 0.000005s | 16901.6 | 220842.9 | 
| rsa | 1024 bits | 0.000164s | 0.000011s | 6100.6 | 94266.4 | 
| rsa | 2048 bits | 0.000798s | 0.000035s | 1252.5 | 28935.0 | 
| rsa | 3072 bits | 0.003693s | 0.000073s | 270.8 | 13658.1 | 
| rsa | 4096 bits | 0.008472s | 0.000125s | 118.0 | 8029.6 | 
| rsa | 7680 bits | 0.067793s | 0.000427s | 14.8 | 2343.9 | 
| rsa | 15360 bits | 0.402000s | 0.001682s | 2.5 | 594.7 | 

