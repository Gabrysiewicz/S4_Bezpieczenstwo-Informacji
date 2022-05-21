<h1 align='center'>SSL</h1>
## Zadanie 6.1. Utworzenie głównego urzędu certyfikacji CA
```
➜  ZXC openssl ecparam -out ca.key -name prime256v1 -genkey
```
```
➜  ZXC openssl req -new -sha256 -key ca.key -out ca.csr
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
Organization Name (eg, company) [Internet Widgits Pty Ltd]:Politechnika
Organizational Unit Name (eg, section) []:PL
Common Name (e.g. server FQDN or YOUR name) []:ZXC
Email Address []:ZXC@zxc.ZXc

Please enter the following 'extra' attributes
to be sent with your certificate request
A challenge password []:guest
An optional company name []:
```
```
➜  ZXC openssl x509 -req -sha256 -days 365 -in ca.csr -signkey ca.key -out ca.csr 
Signature ok
subject=C = PL, ST = Lubelskie, L = Lublin, O = Politechnika, OU = PL, CN = ZXC, emailAddress = ZXC@zxc.ZXc
Getting Private key
```
```
➜  ZXC openssl x509 -noout -text -in ca.csr
Certificate:
    Data:
        Version: 1 (0x0)
        Serial Number:
            06:bd:d8:bd:0e:58:33:02:d2:1e:ee:fc:f6:93:fb:5e:30:92:30:05
        Signature Algorithm: ecdsa-with-SHA256
        Issuer: C = PL, ST = Lubelskie, L = Lublin, O = Politechnika, OU = PL, CN = ZXC, emailAddress = ZXC@zxc.ZXc
        Validity
            Not Before: May 21 20:53:57 2022 GMT
            Not After : May 21 20:53:57 2023 GMT
        Subject: C = PL, ST = Lubelskie, L = Lublin, O = Politechnika, OU = PL, CN = ZXC, emailAddress = ZXC@zxc.ZXc
        Subject Public Key Info:
            Public Key Algorithm: id-ecPublicKey
                Public-Key: (256 bit)
                pub:
                    04:f8:1f:01:3f:80:fc:ed:76:21:7e:47:46:4e:29:
                    5e:f7:0e:2c:dd:19:48:1f:ac:7b:d6:64:4b:7f:b3:
                    82:75:d8:5a:81:31:e8:6d:7e:aa:c6:d3:0e:c5:dc:
                    ac:76:18:76:a2:14:00:a0:80:60:54:d2:2d:71:9f:
                    ea:00:64:b8:de
                ASN1 OID: prime256v1
                NIST CURVE: P-256
    Signature Algorithm: ecdsa-with-SHA256
         30:45:02:20:08:b0:76:c2:5f:dc:e7:71:2e:7a:f0:ca:a7:c1:
         93:6c:f6:d0:71:5e:75:6d:07:e4:b8:55:82:cf:0f:f7:c3:66:
         02:21:00:c3:c8:8b:58:10:88:c9:dd:b5:62:14:90:21:2a:4a:
         7e:26:f0:6b:d0:d8:84:2d:13:49:48:cd:49:08:fa:7e:da
```
## Zad 2
```
➜  ZXC openssl ecparam -out server.key -name prime256v1 -genkey 
➜  ZXC openssl req -new -sha256 -key server.key -out server.csr 
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
Organizational Unit Name (eg, section) []:PL
Common Name (e.g. server FQDN or YOUR name) []:zxc
Email Address []:zxc@zxc.zxc

Please enter the following 'extra' attributes
to be sent with your certificate request
A challenge password []:guest
An optional company name []:
```
```
➜  ZXC openssl x509 -req -in server.csr -CA ca.csr -CAkey ca.key -CAcreateserial -out server.csr -days 365 -sha256 
Signature ok
subject=C = PL, ST = Lubelskie, L = Lublin, O = Polibuda, OU = PL, CN = zxc, emailAddress = zxc@zxc.zxc
Getting CA Private Key
```
```
➜  ZXC openssl x509 -in server.csr -text -noout
Certificate:
    Data:
        Version: 1 (0x0)
        Serial Number:
            17:4f:07:ff:37:66:57:a5:af:46:13:4a:b6:c2:78:3a:79:c9:56:63
        Signature Algorithm: ecdsa-with-SHA256
        Issuer: C = PL, ST = Lubelskie, L = Lublin, O = Politechnika, OU = PL, CN = ZXC, emailAddress = ZXC@zxc.ZXc
        Validity
            Not Before: May 21 21:14:02 2022 GMT
            Not After : May 21 21:14:02 2023 GMT
        Subject: C = PL, ST = Lubelskie, L = Lublin, O = Polibuda, OU = PL, CN = zxc, emailAddress = zxc@zxc.zxc
        Subject Public Key Info:
            Public Key Algorithm: id-ecPublicKey
                Public-Key: (256 bit)
                pub:
                    04:c7:0a:f4:43:e7:1c:7b:f1:fb:04:cd:94:cf:6f:
                    88:81:c6:c2:79:f6:b5:a7:93:fa:c1:c8:f1:01:3c:
                    77:30:b7:e6:90:61:50:90:9f:78:20:d0:26:67:f2:
                    c4:69:c5:cb:f3:2d:bd:89:06:e3:57:60:02:9c:38:
                    0f:2a:ce:96:9b
                ASN1 OID: prime256v1
                NIST CURVE: P-256
    Signature Algorithm: ecdsa-with-SHA256
         30:45:02:20:1e:9a:c1:6f:88:e1:e9:46:ac:1c:83:ae:47:91:
         82:ca:83:27:7d:f0:3c:74:c6:c9:ae:86:30:a2:a1:71:c5:99:
         02:21:00:b4:7d:2f:6e:5e:f9:a3:eb:3d:33:ac:17:65:be:64:
         cb:70:7f:43:19:fe:1f:90:b2:86:82:53:93:e9:97:02:73
```
