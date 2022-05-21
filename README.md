<h1 align='center'>SSH</h1>

## 1. Opisz do czego służy z protokół SSH. Jeżeli serwer ssh nie jest zainstalowany na maszynie wirtualnej zainstaluj go - opisz kroki niezbędne w celu instalacji, podaj nazwę i lokalizację pliku zawierającego konfigurację serwera SSH (podaj fragment jego zawartości)
### Protokol ssh sluzy do bezpiecznego logowania sie przy pomocy IP do powloki systemowej innego klienta/uzytkownika/komputera/servera (urzadzenia udostepniajacego usluge ssh)
### Instalacja Servera ssh
```
sudo apt-get install openssh-server
```
### Lokalizacja i zawartość plików konfiguracyjnych /etc/ssh
```
student@LabVM:/etc/ssh$ ls -la
total 584
drwxr-xr-x   4 root root   4096 maj 17 12:42 .
drwxr-xr-x 135 root root  12288 maj 17 12:42 ..
-rw-r--r--   1 root root 535195 gru  2 23:38 moduli
-rw-r--r--   1 root root   1603 gru  2 23:38 ssh_config
drwxr-xr-x   2 root root   4096 gru  2 23:38 ssh_config.d
-rw-r--r--   1 root root   3289 gru  2 23:38 sshd_config
drwxr-xr-x   2 root root   4096 gru  2 23:38 sshd_config.d
-rw-------   1 root root    505 maj 17 12:42 ssh_host_ecdsa_key
-rw-r--r--   1 root root    172 maj 17 12:42 ssh_host_ecdsa_key.pub
-rw-------   1 root root    399 maj 17 12:42 ssh_host_ed25519_key
-rw-r--r--   1 root root     92 maj 17 12:42 ssh_host_ed25519_key.pub
-rw-------   1 root root   2590 maj 17 12:42 ssh_host_rsa_key
-rw-r--r--   1 root root    564 maj 17 12:42 ssh_host_rsa_key.pub
-rw-r--r--   1 root root    342 maj 17 12:42 ssh_import_id
```
### Przykładowa zawartość sshd_config
```
student@LabVM:/etc/ssh$ head -20 sshd_config
#       $OpenBSD: sshd_config,v 1.103 2018/04/09 20:41:22 tj Exp $

# This is the sshd server system-wide configuration file.  See
# sshd_config(5) for more information.

# This sshd was compiled with PATH=/usr/bin:/bin:/usr/sbin:/sbin

# The strategy used for options in the default sshd_config shipped with
# OpenSSH is to specify options with their default value where
# possible, but leave them commented.  Uncommented options override the
# default value.

Include /etc/ssh/sshd_config.d/*.conf

#Port 22
#AddressFamily any
#ListenAddress 0.0.0.0
#ListenAddress ::

#HostKey /etc/ssh/ssh_host_rsa_key

```
## 2. Opisz i przetestuj opcję Disable Password Authentication
Opcja:  PasswordAuthentication no
uniemożliwia logowianie się do ssh za pośrednictwem hasła
File : sshd_config 
``` 
# To disable tunneled clear text passwords, change to no here!
PasswordAuthentication no
#PermitEmptyPasswords no
```
Terminal: server
```
student@LabVM:/etc/ssh$ systemctl reload sshd.service 
```
Terminal : host(SUSE)
``` 
student@localhost:~> ssh 10.16.107.30
student@10.16.107.30: Permission denied (publickey).
```
## 3. Utwórz wiadomość (banner) pojawiający się w momencie logowania do serwera
File : /etc/ssh/ssh_banner
``` 
Unauthorized access to this device is prohibited!
```
File : sshd_config 
``` 
# no default banner path
Banner /etc/ssh/ssh_banner
```
Terminal : host(SUSE)
``` 
student@localhost:~> ssh 10.16.107.30
Unauthorized access to this device is prohibited!
student@10.16.107.30's password: 
```
## 4. Opisz dostępne opcje związane z kryptografią klucza publicznego i prywatnego. Zaimplementuj na serwerze rozwiązanie z nim związane. Na maszynie klienta (Windows) zainstaluj klienta (putty), na maszynie klienta wygeneruj klucze dla użytkownika student (puttygen) umieścić klucz publiczny na serwerze zrestartuj serwer SSH, sprawdź możliwość zalogowania się na serwerze.
### Automat
1. Konfiguracja sshd_config na serwerze wciąż zakłada uwierzytelnienie hasłem.
2. Generuje swoje klucze.
```
➜  .ssh ssh-keygen -t rsa 
Generating public/private rsa key pair.
Enter file in which to save the key (/home/paranoid/.ssh/id_rsa): 
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/paranoid/.ssh/id_rsa
Your public key has been saved in /home/paranoid/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:871LGzbGOfMHMSrz6N+p/pzmlF1GmTuWB7n3CfJgC2M paranoid@Paranoid
The key's randomart image is:
+---[RSA 3072]----+
|                 |
|               .o|
|              oo.|
|              o+o|
|        SE + o.B=|
|        .o*o*.+=*|
|          .*%.ooo|
|          .+.%.o.|
|         ..oB*O. |
+----[SHA256]-----+
```
3. Umieszczam klucze na serwerze 
```
➜  .ssh ssh-copy-id guest@192.168.8.104
/usr/bin/ssh-copy-id: INFO: Source of key(s) to be installed: "/home/paranoid/.ssh/id_rsa.pub"
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
guest@192.168.8.104's password: 

Number of key(s) added: 1

Now try logging into the machine, with:   "ssh 'guest@192.168.8.104'"
and check to make sure that only the key(s) you wanted were added.
```
4. Na serwerze wyłączam autentykacje hasłem 
5. Loguje się za pośrednitwem klucza
```
➜  .ssh ssh guest@192.168.8.104        
Linux mx 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
No mail.
```
### Manual
1. Konfiguracja sshd_config na serwerze wciąż zakłada uwierzytelnienie hasłem.
2. Generuje swoje klucze.
```
➜  .ssh ssh-keygen -t rsa 
Generating public/private rsa key pair.
Enter file in which to save the key (/home/paranoid/.ssh/id_rsa): 
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/paranoid/.ssh/id_rsa
Your public key has been saved in /home/paranoid/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:871LGzbGOfMHMSrz6N+p/pzmlF1GmTuWB7n3CfJgC2M paranoid@Paranoid
The key's randomart image is:
+---[RSA 3072]----+
|                 |
|               .o|
|              oo.|
|              o+o|
|        SE + o.B=|
|        .o*o*.+=*|
|          .*%.ooo|
|          .+.%.o.|
|         ..oB*O. |
+----[SHA256]-----+
```
3. Umieszczam swój klucz publiczny na serwerze w miejscu ~/.ssh
```
➜  .ssh scp id_rsa.pub guest@192.168.8.104:~/.ssh/ 
guest@192.168.8.104's password: 
id_rsa.pub                                                                                                                  100%  571     1.2MB/s   00:00 
```
4. Tworzę plik authorized_keys w ~/.ssh/
```
➜  .ssh touch authorized_keys
```
5. Umieszczam swój klucz publiczny w pliku authorized_keys
```
➜  .ssh cat id_rsa.pub >> authorized_keys 
```
6. Na serwerze wyłączam autentykacje hasłem 
7. Loguje się za pośrednitwem klucza
```
➜  .ssh ssh guest@192.168.8.104
Linux mx 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
No mail.
```
## 5. Opisz opcję „forwarding” wraz z przykładem jej zastosowania. Zademonstruj użycie tunelowania. (programem nestat wykaż otwarte porty na maszynie kliencie). 
Omów różnice i przykłady zastosowań dla*
- local port forwarding
- remote port forwarding
- dynamic port forwarding

