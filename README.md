<h1 align='center'>Final</h1>

```
student@localhost:~/.ssh> ls -la
razem 24
drwx------  2 student users 4096 06-14 12:35 .
drwxr-xr-x 65 student users 4096 06-14 12:20 ..
-rw-r--r--  1 student users  571 2021-09-01  authorized_keys
-rw-r--r--  1 student users 2602 06-14 12:35 final
-rw-r--r--  1 student users  571 2021-09-01  id_rsa.pub
-rw-r--r--  1 student users  174 06-14 12:30 known_hosts
student@localhost:~/.ssh> chmod 600 final 
student@localhost:~/.ssh> ssh -i /home/student/.ssh/final user3@10.16.107.36
Welcome to Ubuntu 20.04.4 LTS (GNU/Linux 5.4.0-117-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

  System information as of Tue 14 Jun 2022 10:36:44 AM UTC

  System load:  0.0                Processes:               134
  Usage of /:   31.0% of 14.94GB   Users logged in:         1
  Memory usage: 10%                IPv4 address for enp0s3: 10.16.107.36
  Swap usage:   0%

 * Super-optimized for small spaces - read how we shrank the memory
   footprint of MicroK8s to make it the smallest full K8s around.

   https://ubuntu.com/blog/microk8s-memory-optimisation

46 updates can be applied immediately.
To see these additional updates run: apt list --upgradable


Last login: Tue Jun 14 10:35:11 2022 from 10.16.107.13

```
