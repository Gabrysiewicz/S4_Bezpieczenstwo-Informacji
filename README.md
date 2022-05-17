<h1 align='center'>SSH</h1>

# 1. Opisz do czego służy z protokół SSH. Jeżeli serwer ssh nie jest zainstalowany na maszynie wirtualnej zainstaluj go - opisz kroki niezbędne w celu instalacji, podaj nazwę i lokalizację pliku zawierającego konfigurację serwera SSH (podaj fragment jego zawartości)
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
# 3. Utwórz wiadomość (banner) pojawiający się w momencie logowania do serwera)
# 4. Opisz dostępne opcje związane z kryptografią klucza publicznego i prywatnego. Zaimplementuj na serwerze rozwiązanie z nim związane. a. Na maszynie klienta (Windows) zainstaluj klienta (putty), na maszynie klienta wygeneruj klucze dla użytkownika student (puttygen) umieścić klucz publiczny na serwerze zrestartuj serwer SSH, sprawdź możliwość zalogowania się na serwerze.
# 5. Opisz opcję „forwarding” wraz z przykładem jej zastosowania. Zademonstruj użycie tunelowania. (programem nestat wykaż otwarte porty na maszynie kliencie). 
Omów różnice i przykłady zastosowań dla*
- local port forwarding
- remote port forwarding
- dynamic port forwarding

