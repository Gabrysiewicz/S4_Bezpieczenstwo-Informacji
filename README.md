<h1 align='center'>Kopia zapasowa</h1>

<h3> P.7.1.Udokumentuj utworzenie lokalnej kopii zapasowej. Porównaj zawartość katalogów.
Możesz w tym celu użyć polecenia diff. Wyjaśnij, co się stało podczas tworzenia kopii
i dlaczego. </h3>
<h3>Grsync</h3>
<img src='https://github.com/Gabrysiewicz/BI-Szyfry/blob/copy/grsync.png' >

<h3> Rsync </h3>

```
➜  Copies rsync -r dane_nazwisko/ dane_nazwisko_copy
➜  Copies ls *                                      
dane_nazwisko:
file1   file11  file13  file15  file17  file19  file20  file22  file24  file26  
file28  file3   file31  file33  file35  file37  file39  file40  file42  file44  
file46  file48  file5   file7   file9   file10  file12  file14  file16  file18  
file2   file21  file23  file25  file27  file29  file30  file32  file34  file36  
file38  file4   file41  file43  file45  file47  file49  file6  file8

dane_nazwisko_copy:
file1   file11  file13  file15  file17  file19  file20  file22  file24  file26
file28  file3   file31  file33  file35  file37  file39  file40  file42  file44
file46  file48  file5   file7  file9   file10  file12  file14   file16  file18
file2   file21  file23  file25  file27  file29  file30  file32  file34  file36
file38  file4   file41  file43  file45  file47  file49  file6   file8
```

```
➜  Copies ls *
dane_nazwisko:
file1   file12  file15  file18  file20  file23  file26  file29  file31  file34
file37  file4   file42  file45  file48  file6   file9   file10  file13  file16
file19  file21  file24  file27  file3   file32  file35  file38  file40  file43
file46  file49  file7   img1.png  file11  file14  file17  file2   file22
file25  file28  file30  file33  file36  file39  file41  file44  file47  file5   file8  img2.jpeg

dane_nazwisko_copy:
file1   file12  file15  file18  file20  file23  file26  file29  file31  file34
file37  file4   file42  file45  file48  file6  file9   file10  file13  file16 
file19  file21  file24  file27  file3   file32  file35  file38  file40  file43 
file46  file49  file7   img3.jpeg  file11  file14  file17  file2   file22  file25 
file28  file30  file33  file36  file39  file41  file44  file47  file5   file8  img4.jpeg

➜  Copies rsync -av --delete dane_nazwisko/ dane_nazwisko_copy
sending incremental file list
deleting img4.jpeg
deleting img3.jpeg
./
file1
...
sent 638,084 bytes  received 1,014 bytes  1,278,196.00 bytes/sec
total size is 635,185  speedup is 0.99
```

Rsync dodatkowe opcje
```
-a, --append     append data onto shorter files     - dokleja zmienioną zawarość
-v, --verbose    increase verbosity 
-delete         delete extraneous files from destination dirs   - usuwa nadprogramowe pliki 
```
<h3> P.7.2. Zaplanuj tworzenie kopi zapasowej katalogu dane_nazwisko w czwartki o godzinie
21:15. Udokumentuj wykonanie ćwiczenia. </h3>

Crontab 
```
15 21 * * 4 rsync -av --delete ~/Copies/dane_nazwisko ~/Copies/dane_nazwisko_copy
```

<h3> P.7.3. Napisz skrypt, który będzie tworzył kopię zapasową, co godzinę w dni robocze. Dodaj
wywołanie skryptu do cron-a. Sprawdź działanie opracowanego rozwiązania i je udokumentuj. </h3>

Script
```
#!/bin/bash

rsync -av --delete ~/Copies/dane_nazwisko ~/Copies/dane_nazwisko_copy
```

Crontab
```
0 * * * 1-5 sh ~/.scripts/script_copy
```

<h3> P.7.4. Udokumentuj i opisz etapy wykonanie ćwiczenia. </h3>
Host : 

```
➜  BI_Backup rsync -av --delete -e ssh ~/BI_Backup/ guest@192.168.0.21:~/ssh_copy
guest@192.168.0.21's password: 
sending incremental file list
./
100kB
10MB
10kB
DirA/
DirB/
DirC/

sent 10,601,337 bytes  received 92 bytes  3,028,979.71 bytes/sec
total size is 10,598,400  speedup is 1.00
```

Guest : 

```
➜  ssh_copy ls
100kB  10kB  10MB  DirA  DirB  DirC
```

<h3> P.7.5. Udokumentuj i opisz etapy wykonanie ćwiczenia.  </h3>

Konfiguracja guest

```
➜  .ssh whoami
guest
➜  .ssh ls
authorized_keys  id_rsa  id_rsa.pub  known_hosts
➜  .ssh head *
==> authorized_keys <==
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDXK0IiIeVBZi+GtxehMkEXwAmY31XkR42UEs6HxPT4M54EMhWJ8Eb2/dKNiSIYkr2vLHWGv4vncmnaq
+eztIA4dVyyNtOFFZXx9qvh1kQUVrNkeFHZ7Y2WOMfE6Dq3c4HjzuwBK3670LNxDEkdeJ+ZbVlVoTigqpHOTjE6im/dZZ7zP0XTFpY/Nsph1nTUrlotGp
p6HdNRV5487JSV8GjaG8jHhcGYLl4HRA+Qhz6mrnXSA2Arm/O0H1f4ODo57zLjZPQVtJkaI1RuGM8Fy/lbYUQrwgrx65CR4ojpf6bD5huaCukGxiP/k5h
mcrQ0aGKp364yDyZr83fzo2hu0zLL guest2@Guest2

==> id_rsa <==
-----BEGIN OPENSSH PRIVATE KEY-----
b3BlbnNzaC1rZXktdjEAAAAABG5vbmUAAAAEbm9uZQAAAAAAAAABAAABFwAAAAdzc2gtcn
NhAAAAAwEAAQAAAQEAxXbXM4J+aq7YcdvitP+ZyueIL0j1cLIeJk0rm1/wrYR2YJmZMNBW
I8X6NS/WOrBtuK1LkbospR6WHskvVj+sRmfD+Bh9m/vqhBGUinGM+NFVGWlO1Q6sqyFLwN
NnYdUCNTln/a2oy0FIouKSorO1Z3KuTICQHGJglqWsE/3TCi1O4hP7vnv6TsJfpeH7B5eW
XP2EBimznzgypn04+DCeXNVa+oLlPVrbfn7BqvX7rcY9/iuLLySHB6vWNY5PTzui/8PHnQ
04q1DeBKd6d0wH4wfIg8AoclL86pkljIVeP+N/InKJAYsjStAzr/L7faU/XvzwU3l+WEiq
lVrB8iXU5QAAA8BJ+qaySfqmsgAAAAdzc2gtcnNhAAABAQDFdtczgn5qrthx2+K0/5nK54
gvSPVwsh4mTSubX/CthHZgmZkw0FYjxfo1L9Y6sG24rUuRuiylHpYeyS9WP6xGZ8P4GH2b
++qEEZSKcYz40VUZaU7VDqyrIUvA02dh1QI1OWf9rajLQUii4pKis7Vncq5MgJAcYmCWpa

==> id_rsa.pub <==
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDFdtczgn5qrthx2+K0/5nK54gvSPVwsh4mTSubX/CthHZgmZkw0FYjxfo1L9Y6sG24rUuRuiylHpYe
yS9WP6xGZ8P4GH2b++qEEZSKcYz40VUZaU7VDqyrIUvA02dh1QI1OWf9rajLQUii4pKis7Vncq5MgJAcYmCWpawT/dMKLU7iE/u+e/pOwl+l4fsHl5Z
c/YQGKbOfODKmfTj4MJ5c1Vr6guU9Wtt+fsGq9futxj3+K4svJIcHq9Y1jk9PO6L/w8edDTirUN4Ep3p3TAfjB8iDwChyUvzqmSWMhV4/438icokBiy
K0DOv8vt9pT9e/PBTeX5YSKqVWsHyJdTl guest@mx

==> known_hosts <==
192.168.0.22 ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBF2RywLnwsfliL3N7WsulqIe4He
Qt4+XjTfahDZnhQUcbw0PssPFOPNtHtRxJx4EoBHcRzUOhAuKAmR/p/PBA+M=
```

Konfiguracja guest2

```
➜  .ssh whoami
guest2
➜  .ssh ls
authorized_keys  id_rsa  id_rsa.pub  known_hosts
➜  .ssh head *
==> authorized_keys <==
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDFdtczgn5qrthx2+K0/5nK54gvSPVwsh4mTSubX/CthHZgmZkw0FYjxf
o1L9Y6sG24rUuRuiylHpYeyS9WP6xGZ8P4GH2b++qEEZSKcYz40VUZaU7VDqyrIUvA02dh1QI1OWf9rajLQUii4pKis7V
ncq5MgJAcYmCWpawT/dMKLU7iE/u+e/pOwl+l4fsHl5Zc/YQGKbOfODKmfTj4MJ5c1Vr6guU9Wtt+fsGq9futxj3+K4sv
JIcHq9Y1jk9PO6L/w8edDTirUN4Ep3p3TAfjB8iDwChyUvzqmSWMhV4/438icokBiyNK0DOv8vt9pT9e/PBTeX5YSKqVW
sHyJdTl guest@mx

==> id_rsa <==
-----BEGIN OPENSSH PRIVATE KEY-----
b3BlbnNzaC1rZXktdjEAAAAACmFlczI1Ni1jdHIAAAAGYmNyeXB0AAAAGAAAABC6q/3hsh
/2blnJqNUavTrjAAAAEAAAAAEAAAEXAAAAB3NzaC1yc2EAAAADAQABAAABAQDXK0IiIeVB
Zi+GtxehMkEXwAmY31XkR42UEs6HxPT4M54EMhWJ8Eb2/dKNiSIYkr2vLHWGv4vncmnaq+
eztIA4dVyyNtOFFZXx9qvh1kQUVrNkeFHZ7Y2WOMfE6Dq3c4HjzuwBK3670LNxDEkdeJ+Z
bVlVoTigqpHOTjE6im/dZZ7zP0XTFpY/Nsph1nTUrlotGpp6HdNRV5487JSV8GjaG8jHhc
GYLl4HRA+Qhz6mrnXSA2Arm/O0H1f4ODo57zLjZPQVtJkaI1RuGM8Fy/lbYUQrwgrx65CR
4ojpf6bD5huaCukGxiP/k5hmcrQ0aGKp364yDyZr83fzo2hu0zLLAAAD0Jc5s6uUrPsAx/
j0pCpp8QPS7RFBjd+6HW7n9R826tK62leLO58EGgxqQCFrYj1qQvbrwGpuTphVafWYKjaq
hcp8K8yEU3A3+f67l8LsSYJlP2s6pyPZLNFtS+LcnWekPfE3i3iNZ/Tz+ut27OMDVs6VV1

==> id_rsa.pub <==
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDXK0IiIeVBZi+GtxehMkEXwAmY31XkR42UEs6HxPT4M54EMhWJ8E
b2/dKNiSIYkr2vLHWGv4vncmnaq+eztIA4dVyyNtOFFZXx9qvh1kQUVrNkeFHZ7Y2WOMfE6Dq3c4HjzuwBK3670LNx
DEkdeJ+ZbVlVoTigqpHOTjE6im/dZZ7zP0XTFpY/Nsph1nTUrlotGpp6HdNRV5487JSV8GjaG8jHhcGYLl4HRA+Qh
z6mrnXSA2Arm/O0H1f4ODo57zLjZPQVtJkaI1RuGM8Fy/lbYUQrwgrx65CR4ojpf6bD5huaCukGxiP/k5hmcrQ0aGK
p364yDyZr83fzo2hu0zLL guest2@Guest2

==> known_hosts <==
192.168.0.21 ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBB
F2RywLnwsfliL3N7WsulqIe4HeQt4+XjTfahDZnhQUcbw0PssPFOPNtHtRxJx4EoBHcRzUOhAuKAmR/p/PBA+M=
```

Guest1

```
➜  ~ scp -r ssh_copy guest2@192.168.0.22:~  
10kB                                                                          100%   10KB   3.2MB/s   00:00    
100kB                                                                         100%  100KB  25.3MB/s   00:00    
10MB                                                                          100%   10MB  56.3MB/s   00:00  
```

<h3> P.7.6. W sprawozdaniu umieść treść skryptu, wpis z cron-a oraz zrzut ekranu prezentujący
efekt działania skryptu. Odpowiedź na pytanie: Dlaczego skrypt wywoływany przez
cron może wykonać kopię katalogu użytkownika, skoro użytkownik nie jest
zalogowany? </h3>

```
➜  ~ sudo fdisk -l 
Disk /dev/sda: 15 GiB, 16106127360 bytes, 31457280 sectors
Disk model: VBOX HARDDISK   
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0x00a5af70

Device     Boot    Start      End  Sectors Size Id Type
/dev/sda1  *        2048 14616575 14614528   7G 83 Linux
/dev/sda2       14616576 16713727  2097152   1G 83 Linux


Disk /dev/sdb: 100 MiB, 104857600 bytes, 204800 sectors
Disk model: VBOX HARDDISK   
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


➜  ~ sudo mkfs.ext4 /dev/sdb
mke2fs 1.44.5 (15-Dec-2018)
Creating filesystem with 102400 1k blocks and 25688 inodes
Filesystem UUID: 4d2e3c50-506d-4f49-9a83-f41cee889c1d
Superblock backups stored on blocks: 
	8193, 24577, 40961, 57345, 73729

Allocating group tables: done                            
Writing inode tables: done                            
Creating journal (4096 blocks): done
Writing superblocks and filesystem accounting information: done 

➜  ~ sudo mkdir -p /mnt/archive       
➜  ~ sudo mount /dev/sdb /mnt/archive
➜  ~ sudo df -h
Filesystem      Size  Used Avail Use% Mounted on
udev            964M     0  964M   0% /dev
tmpfs           200M  2.3M  198M   2% /run
/dev/sda1       6.8G  6.4G   42M 100% /
tmpfs           5.0M  8.0K  5.0M   1% /run/lock
tmpfs           604M  8.0K  604M   1% /dev/shm
cgroup           12K     0   12K   0% /sys/fs/cgroup
tmpfs           200M  8.0K  200M   1% /run/user/1000
/dev/sdb         93M  1.6M   85M   2% /mnt/archive
```

Script:
```
#!/bin/bash
avail=$(sudo df | grep "/mnt/archive" | awk -F ' ' '{print $(NF-2)}' | awk '{t=length($0)}END{print substr($0,0,t-1)}')
avail_w_bytes=$(sudo df -h | grep "/mnt/archive" | awk -F ' ' '{print $(NF-2)}')
file_date=$(date +"%F-%H-%M-%S")
USER=guest
ARCHIVE="/mnt/archive/archive_"$file_date".tar.gz"
if [[ $avail -le 3000 ]]; then
	echo -e "\033[0;33mFree space: "$avail_w_bytes" (<30MB)"
	oldest_archive=$(ls -lh --sort=time /mnt/archive | grep "archive" | awk -F ' ' '{print $NF}' | awk 'END{print}')
	echo -e "The following file will be deleted: "/mnt/archive/$oldest_archive"\033[0m"
	sudo rm /mnt/archive/$oldest_archive
	echo -e "\033[0;31m"/mnt/archive/$oldest_archive" has been deleted\033[0m"
	avail_w_bytes=$(sudo df -h | grep "/mnt/archive" | awk -F ' ' '{print $(NF-2)}')
	echo -e "\033[0;32mThere is "$avail_w_bytes" of free space \033[0m"
	sudo tar -czf $ARCHIVE ~
	sudo chmod 600 $ARCHIVE
	sudo chown $USER $ARCHIVE
	echo -e "\033[0;32mNew archive has been created. \033[0m"
elif [[ $avail -gt 3000 ]]; then
	avail_w_bytes=$(sudo df -h | grep "/mnt/archive" | awk -F ' ' '{print $(NF-2)}')
	echo -e "\033[0;32mThere is "$avail_w_bytes" of free space \033[0m"
	sudo tar -czf $ARCHIVE ~
	sudo chmod 600 $ARCHIVE
	sudo chown $USER $ARCHIVE
	echo -e "\033[0;32mNew archive has been created. \033[0m"

fi

```
Script przyrostowy:
```
#!/bin/bash
avail=$(sudo df | grep "/mnt/archive" | awk -F ' ' '{print $(NF-2)}' | awk '{t=length($0)}END{print substr($0,0,t-1)}')
avail_w_bytes=$(sudo df -h | grep "/mnt/archive" | awk -F ' ' '{print $(NF-2)}')
file_date=$(date +"%F-%H-%M-%S")
USER=guest
ARCHIVE="/mnt/archive/archive_"$file_date".tar.gz"
if [[ $avail -le 3000 ]]; then
	echo -e "\033[0;33mFree space: "$avail_w_bytes" (<30MB)"
	oldest_archive=$(ls -lh --sort=time /mnt/archive | grep "archive" | awk -F ' ' '{print $NF}' | awk 'END{print}')
	echo -e "The following file will be deleted: "/mnt/archive/$oldest_archive"\033[0m"
	sudo rm /mnt/archive/$oldest_archive
	echo -e "\033[0;31m"/mnt/archive/$oldest_archive" has been deleted\033[0m"
	avail_w_bytes=$(sudo df -h | grep "/mnt/archive" | awk -F ' ' '{print $(NF-2)}')
	echo -e "\033[0;32mThere is "$avail_w_bytes" of free space \033[0m"
	sudo tar -czf $ARCHIVE ~
	sudo chmod 600 $ARCHIVE
	sudo chown $USER $ARCHIVE
	echo -e "\033[0;32mNew archive has been created. \033[0m"
elif [[ $avail -gt 3000 ]]; then
	avail_w_bytes=$(sudo df -h | grep "/mnt/archive" | awk -F ' ' '{print $(NF-2)}')
	echo -e "\033[0;32mThere is "$avail_w_bytes" of free space \033[0m"
	newest_archive=$(ls -lh --sort=time /mnt/archive | grep "archive" | awk -F ' ' '{print $NF}' | awk 'NR==1{print}')
	sudo tar --append -file=$newest_archive ~
	sudo chmod 600 $ARCHIVE
	sudo chown $USER $ARCHIVE
	echo -e "\033[0;32mNew archive has been created. \033[0m"
fi
```

Przykład wywołania:
```
➜  ~ ./script_total.sh  
Free space: 2.9M (<30MB)
The following file will be deleted: /mnt/archive/archive_2022-05-29-22-11-27.tar.gz
/mnt/archive/archive_2022-05-29-22-11-27.tar.gz has been deleted
There is 85M of free space 
tar: Removing leading `/' from member names
tar: /home/guest/.cache/keyring-DQFWM1/control: socket ignored
New archive has been created. 
```

Crontab:
```
0 22 * * 1-4 sh ~/.scripts/script_append.sh
0 22 * * 5 sh ~/.scripts/script_total.sh
```

<h3> P.7.7. W sprawozdaniu umieść treść niezbędnych skryptów, zrzuty ekranu prezentujące
działanie opracowanego rozwiązania. Wyjaśnij, dlaczego niniejsza kopia jest kopią
przyrostową. Jeśli w archiwum widoczne są wszystkie pliki i katalogi (tak jak w kopii
pełnej) udowodnij, że jest to kopia przyrostowa. </h3>
