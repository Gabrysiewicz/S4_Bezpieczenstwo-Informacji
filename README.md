<h1 align='center'>SSH</h1>

# 1. Opisz do czego służy z protokół SSH. Jeżeli serwer ssh nie jest zainstalowany na maszynie wirtualnej zainstaluj go - opisz kroki niezbędne w celu instalacji, podaj nazwę i lokalizację pliku zawierającego konfigurację serwera SSH (podaj fragment jego zawartości)
### Protokol ssh sluzy do bezpiecznego logowania sie do powloki systemowej innego klienta/uzytkownika/komputera/servera (urzadzenia udostepniajacego usluge ssh)
```
sudo apt-get install openssh-server
```
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
# 2. Opisz i przetestuj opcję Disable Password Authentication
``` sshd_config
# To disable tunneled clear text passwords, change to no here!
PasswordAuthentication no
#PermitEmptyPasswords no
```
``` terminal (host(SUSE))
student@LabVM:/etc/ssh$ systemctl reload sshd.service 
==== AUTHENTICATING FOR org.freedesktop.systemd1.manage-units ===
Authentication is required to reload 'ssh.service'.
Authenticating as: student,,, (student)
Password: 
==== AUTHENTICATION COMPLETE ===
student@LabVM:/etc/ssh$ exit
logout
Connection to 10.16.107.30 closed.
student@localhost:~> ssh 10.16.107.30
student@10.16.107.30: Permission denied (publickey).
```
# 3. Utwórz wiadomość (banner) pojawiający się w momencie logowania do serwera)
``` ssh_banner
Unauthorized access to this device is prohibited!
```
``` sshd_config
# no default banner path
Banner /etc/ssh/ssh_banner
```
``` terminal (host(SUSE))
student@localhost:~> ssh 10.16.107.30
Unauthorized access to this device is prohibited!
student@10.16.107.30's password: 
```
# 4. Opisz dostępne opcje związane z kryptografią klucza publicznego i prywatnego. Zaimplementuj na serwerze rozwiązanie z nim związane. a. Na maszynie klienta (Windows) zainstaluj klienta (putty), na maszynie klienta wygeneruj klucze dla użytkownika student (puttygen) umieścić klucz publiczny na serwerze zrestartuj serwer SSH, sprawdź możliwość zalogowania się na serwerze.
``` terminal
student@localhost:~> ssh-keygen -help
Enter file in which the key is (/home/student/.ssh/id_rsa): ^C
student@localhost:~> man ssh-keygen 
student@localhost:~> ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/home/student/.ssh/id_rsa): my_keys
Enter passphrase (empty for no passphrase): (paranoid)
Enter same passphrase again: (paranoid)
Your identification has been saved in my_keys
Your public key has been saved in my_keys.pub
The key fingerprint is:
SHA256:2VYlHDx0X7ic4jevrsYaPA4dTbYzBGMRgb10oWxGNCc student@localhost
The key's randomart image is:
+---[RSA 3072]----+
|         +EB*oo..|
|        .+oB=+...|
|         .=o=o o.|
|         =.*..+  |
|        S +.=.   |
|         + ..oo  |
|        . =. . o |
|         o oo   .|
|          oo.oo. |
+----[SHA256]-----+
student@localhost:~> cat /home/student/.ssh/id_rsa.pub 
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQDcX/doLEmwDSqc8YoCfBFVK6JjMB5WeoPGpv7Yqj0Yf+etIoeCB/WbQJbWBvnXnPUrxA+qnbqKpdC5xtN9llyHjg9i7WPhPiv02aHxTfgnD88YpeOo0lqGtJ0IdqMyOnTKfNVZGSYKjnsORmjr88twXHI40sbLlnXUr6nxR5YawJj32WdY1wMATedpEaSmPZp94Vqksrq9qIjXNKvK05D/IwAKqIn4LwrGvbcwsNxebM8721+GcJJjqryz8QRUZH3eZk+7TsCfQ8VUBzQg3+gOhwtlecD/T7H/JE62WhywrZE+G5Yfm4lxHYqQqeKiHpAXDEmxI/4Lu+HPzu5juq1EA/zThg8trFbU7LT1nSsv2vuYJYdPTRddlcokswpmDNWUzsGqNAvxAOEgY1H/PODnZ8vjk2xmZTJb5S9m451vJ2INu/i+jGn0mV42rwnPy5W0Q1Vpjs7dTNUQRUXWGzVnTG9mY9XPIe279DtLNNgPreUmNe4RnlWlBySa8gyhh98= student@localhost
```
``` sshd_config (server)
HostKey /etc/ssh/ssh_host_rsa_key
#HostKey /etc/ssh/ssh_host_ecdsa_key
#HostKey /etc/ssh/ssh_host_ed25519_key

PubkeyAuthentication yes

# To disable tunneled clear text passwords, change to no here!
PasswordAuthentication no
#PermitEmptyPasswords no
```
# 5. Opisz opcję „forwarding” wraz z przykładem jej zastosowania. Zademonstruj użycie tunelowania. (programem nestat wykaż otwarte porty na maszynie kliencie). 
Omów różnice i przykłady zastosowań dla*
- local port forwarding
- remote port forwarding
- dynamic port forwarding

