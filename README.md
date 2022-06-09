<h1 align='center'>RAID</h1>

<h3> Zadanie 8.1. Tworzenie macierzy RAID1 </h3>

```
➜  ~ sudo ls /dev/sd*
/dev/sda  /dev/sda1  /dev/sda2	/dev/sda3  /dev/sdb  /dev/sdc
➜  ~ sudo fdisk -l
Disk /dev/sda: 128 GiB, 137438953472 bytes, 268435456 sectors
Disk model: VBOX HARDDISK   
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0xdc7cf971

Device     Boot     Start       End   Sectors Size Id Type
/dev/sda1            2048 125831167 125829120  60G 83 Linux
/dev/sda2       125831168 142608383  16777216   8G 82 Linux swap / Solaris
/dev/sda3       142608384 268435455 125827072  60G 83 Linux


Disk /dev/sdb: 100 MiB, 104857600 bytes, 204800 sectors
Disk model: VBOX HARDDISK   
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/sdc: 100 MiB, 104857600 bytes, 204800 sectors
Disk model: VBOX HARDDISK   
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes

➜  ~ sudo mdadm --create /dev/md1 --level=raid1 --raid-devices=2 /dev/sdb /dev/sdc  
mdadm: Note: this array has metadata at the start and
    may not be suitable as a boot device.  If you plan to
    store '/boot' on this device please ensure that
    your boot-loader understands md/v1.x metadata, or use
    --metadata=0.90
Continue creating array? 
Continue creating array? (y/n) y
mdadm: Defaulting to version 1.2 metadata
mdadm: array /dev/md1 started.

➜  ~ sudo mdadm --query --detail /dev/md1
/dev/md1:
           Version : 1.2
     Creation Time : Thu Jun  9 21:08:09 2022
        Raid Level : raid1
        Array Size : 101376 (99.00 MiB 103.81 MB)
     Used Dev Size : 101376 (99.00 MiB 103.81 MB)
      Raid Devices : 2
     Total Devices : 2
       Persistence : Superblock is persistent

       Update Time : Thu Jun  9 21:08:10 2022
             State : clean 
    Active Devices : 2
   Working Devices : 2
    Failed Devices : 0
     Spare Devices : 0

Consistency Policy : resync

              Name : Neo:1  (local to host Neo)
              UUID : 78167d4c:81e269e4:092bbf83:df7b5d22
            Events : 18

    Number   Major   Minor   RaidDevice State
       0       8       16        0      active sync   /dev/sdb
       1       8       32        1      active sync   /dev/sdc
       
➜  ~ sudo mkfs.ext4 /dev/md1
mke2fs 1.44.5 (15-Dec-2018)
Creating filesystem with 101376 1k blocks and 25376 inodes
Filesystem UUID: d2b78d13-37ff-4408-98eb-73c7a29617ec
Superblock backups stored on blocks: 
	8193, 24577, 40961, 57345, 73729

Allocating group tables: done                            
Writing inode tables: done                            
Creating journal (4096 blocks): done
Writing superblocks and filesystem accounting information: done 

➜  ~ sudo cp -a Directory1 Directory2  
➜  ~ df -h 
System plików  rozm. użyte dost. %uż. zamont. na
udev            954M     0  954M   0% /dev
tmpfs           199M  2,3M  197M   2% /run
/dev/sda1        59G  7,0G   49G  13% /
tmpfs           5,0M  8,0K  5,0M   1% /run/lock
tmpfs           2,0G     0  2,0G   0% /dev/shm
/dev/sda3        59G  259M   56G   1% /home
cgroup           12K     0   12K   0% /sys/fs/cgroup
tmpfs           199M   12K  199M   1% /run/user/1000

➜  ~ sudo mdadm --detail /dev/md127
/dev/md127:
           Version : 1.2
     Creation Time : Thu Jun  9 21:08:09 2022
        Raid Level : raid1
        Array Size : 101376 (99.00 MiB 103.81 MB)
     Used Dev Size : 101376 (99.00 MiB 103.81 MB)
      Raid Devices : 2
     Total Devices : 3
       Persistence : Superblock is persistent

       Update Time : Thu Jun  9 23:09:03 2022
             State : clean 
    Active Devices : 2
   Working Devices : 3
    Failed Devices : 0
     Spare Devices : 1

Consistency Policy : resync

              Name : Neo:1  (local to host Neo)
              UUID : 78167d4c:81e269e4:092bbf83:df7b5d22
            Events : 21

    Number   Major   Minor   RaidDevice State
       0       8       16        0      active sync   /dev/sdb
       1       8       32        1      active sync   /dev/sdc

       2       8       48        -      spare   /dev/sdd
```

```
➜  ~ sudo mdadm -E /dev/sdb
mdadm: No md superblock detected on /dev/sdb.
➜  ~ sudo mdadm -E /dev/sdc
mdadm: No md superblock detected on /dev/sdc.
➜  ~ fdisk /dev/sdb
zsh: command not found: fdisk
➜  ~ sudo fdisk /dev/sdb

Welcome to fdisk (util-linux 2.33.1).
Changes will remain in memory only, until you decide to write them.
Be careful before using the write command.

Device does not contain a recognized partition table.
Created a new DOS disklabel with disk identifier 0xbee25cc4.

Command (m for help): n
Partition type
   p   primary (0 primary, 0 extended, 4 free)
   e   extended (container for logical partitions)
Select (default p): p
Partition number (1-4, default 1): 1
First sector (2048-204799, default 2048): 
Last sector, +/-sectors or +/-size{K,M,G,T,P} (2048-204799, default 204799): 

Created a new partition 1 of type 'Linux' and of size 99 MiB.

Command (m for help): p
Disk /dev/sdb: 100 MiB, 104857600 bytes, 204800 sectors
Disk model: VBOX HARDDISK   
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0xbee25cc4

Device     Boot Start    End Sectors Size Id Type
/dev/sdb1        2048 204799  202752  99M 83 Linux

Command (m for help): t

Selected partition 1
Hex code (type L to list all codes): L

 0  Empty           24  NEC DOS         81  Minix / old Lin bf  Solaris        
 1  FAT12           27  Hidden NTFS Win 82  Linux swap / So c1  DRDOS/sec (FAT-
 2  XENIX root      39  Plan 9          83  Linux           c4  DRDOS/sec (FAT-
 3  XENIX usr       3c  PartitionMagic  84  OS/2 hidden or  c6  DRDOS/sec (FAT-
 4  FAT16 <32M      40  Venix 80286     85  Linux extended  c7  Syrinx         
 5  Extended        41  PPC PReP Boot   86  NTFS volume set da  Non-FS data    
 6  FAT16           42  SFS             87  NTFS volume set db  CP/M / CTOS / .
 7  HPFS/NTFS/exFAT 4d  QNX4.x          88  Linux plaintext de  Dell Utility   
 8  AIX             4e  QNX4.x 2nd part 8e  Linux LVM       df  BootIt         
 9  AIX bootable    4f  QNX4.x 3rd part 93  Amoeba          e1  DOS access     
 a  OS/2 Boot Manag 50  OnTrack DM      94  Amoeba BBT      e3  DOS R/O        
 b  W95 FAT32       51  OnTrack DM6 Aux 9f  BSD/OS          e4  SpeedStor      
 c  W95 FAT32 (LBA) 52  CP/M            a0  IBM Thinkpad hi ea  Rufus alignment
 e  W95 FAT16 (LBA) 53  OnTrack DM6 Aux a5  FreeBSD         eb  BeOS fs        
 f  W95 Ext'd (LBA) 54  OnTrackDM6      a6  OpenBSD         ee  GPT            
10  OPUS            55  EZ-Drive        a7  NeXTSTEP        ef  EFI (FAT-12/16/
11  Hidden FAT12    56  Golden Bow      a8  Darwin UFS      f0  Linux/PA-RISC b
12  Compaq diagnost 5c  Priam Edisk     a9  NetBSD          f1  SpeedStor      
14  Hidden FAT16 <3 61  SpeedStor       ab  Darwin boot     f4  SpeedStor      
16  Hidden FAT16    63  GNU HURD or Sys af  HFS / HFS+      f2  DOS secondary  
17  Hidden HPFS/NTF 64  Novell Netware  b7  BSDI fs         fb  VMware VMFS    
18  AST SmartSleep  65  Novell Netware  b8  BSDI swap       fc  VMware VMKCORE 
1b  Hidden W95 FAT3 70  DiskSecure Mult bb  Boot Wizard hid fd  Linux raid auto
1c  Hidden W95 FAT3 75  PC/IX           bc  Acronis FAT32 L fe  LANstep        
1e  Hidden W95 FAT1 80  Old Minix       be  Solaris boot    ff  BBT            
Hex code (type L to list all codes): fd
Changed type of partition 'Empty' to 'Linux raid autodetect'.

Command (m for help): p
Disk /dev/sdb: 100 MiB, 104857600 bytes, 204800 sectors
Disk model: VBOX HARDDISK   
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0xbee25cc4

Device     Boot Start    End Sectors Size Id Type
/dev/sdb1        2048 204799  202752  99M fd Linux raid autodetect

Command (m for help): w
The partition table has been altered.
Calling ioctl() to re-read partition table.
Syncing disks.

➜  ~ sudo mdadm -E /dev/sd[b-c]
/dev/sdb:
   MBR Magic : aa55
Partition[0] :       202752 sectors at         2048 (type fd)
/dev/sdc:
   MBR Magic : aa55
Partition[0] :       202752 sectors at         2048 (type fd)

➜  ~ sudo mdadm --create /dev/md0 --level=mirror --raid-devices=2 /dev/sd[b-c]1
mdadm: Note: this array has metadata at the start and
    may not be suitable as a boot device.  If you plan to
    store '/boot' on this device please ensure that
    your boot-loader understands md/v1.x metadata, or use
    --metadata=0.90
Continue creating array? y
mdadm: Defaulting to version 1.2 metadata
mdadm: array /dev/md0 started.
➜  ~ sudo mdadm -E /dev/sd[b-c]1
/dev/sdb1:
          Magic : a92b4efc
        Version : 1.2
    Feature Map : 0x0
     Array UUID : f3c49a5e:b068219a:ac578b9c:eb48f245
           Name : Neo:0  (local to host Neo)
  Creation Time : Fri Jun 10 00:28:50 2022
     Raid Level : raid1
   Raid Devices : 2

 Avail Dev Size : 200704 (98.00 MiB 102.76 MB)
     Array Size : 100352 (98.00 MiB 102.76 MB)
    Data Offset : 2048 sectors
   Super Offset : 8 sectors
   Unused Space : before=1968 sectors, after=0 sectors
          State : clean
    Device UUID : 1215b7b3:51f9a317:620c36ca:43cbd835

    Update Time : Fri Jun 10 00:28:51 2022
  Bad Block Log : 512 entries available at offset 16 sectors
       Checksum : 4f9279b4 - correct
         Events : 18


   Device Role : Active device 0
   Array State : AA ('A' == active, '.' == missing, 'R' == replacing)
/dev/sdc1:
          Magic : a92b4efc
        Version : 1.2
    Feature Map : 0x0
     Array UUID : f3c49a5e:b068219a:ac578b9c:eb48f245
           Name : Neo:0  (local to host Neo)
  Creation Time : Fri Jun 10 00:28:50 2022
     Raid Level : raid1
   Raid Devices : 2

 Avail Dev Size : 200704 (98.00 MiB 102.76 MB)
     Array Size : 100352 (98.00 MiB 102.76 MB)
    Data Offset : 2048 sectors
   Super Offset : 8 sectors
   Unused Space : before=1968 sectors, after=0 sectors
          State : clean
    Device UUID : 9a415099:f0325b97:57164f3a:054bd9ac

    Update Time : Fri Jun 10 00:28:51 2022
  Bad Block Log : 512 entries available at offset 16 sectors
       Checksum : 9bfc6993 - correct
         Events : 18


   Device Role : Active device 1
   Array State : AA ('A' == active, '.' == missing, 'R' == replacing)

➜  ~ sudo mdadm --detail /dev/md0
/dev/md0:
           Version : 1.2
     Creation Time : Fri Jun 10 00:28:50 2022
        Raid Level : raid1
        Array Size : 100352 (98.00 MiB 102.76 MB)
     Used Dev Size : 100352 (98.00 MiB 102.76 MB)
      Raid Devices : 2
     Total Devices : 2
       Persistence : Superblock is persistent

       Update Time : Fri Jun 10 00:28:51 2022
             State : clean 
    Active Devices : 2
   Working Devices : 2
    Failed Devices : 0
     Spare Devices : 0

Consistency Policy : resync

              Name : Neo:0  (local to host Neo)
              UUID : f3c49a5e:b068219a:ac578b9c:eb48f245
            Events : 18

    Number   Major   Minor   RaidDevice State
       0       8       17        0      active sync   /dev/sdb1
       1       8       33        1      active sync   /dev/sdc1

➜  ~ sudo mkfs.ext4 /dev/md0
mke2fs 1.44.5 (15-Dec-2018)
Creating filesystem with 100352 1k blocks and 25168 inodes
Filesystem UUID: aedc9d01-f402-4ee7-be72-0a3b9289df6d
Superblock backups stored on blocks: 
	8193, 24577, 40961, 57345, 73729

Allocating group tables: done                            
Writing inode tables: done                            
Creating journal (4096 blocks): done
Writing superblocks and filesystem accounting information: done 

➜  ~ sudo mkdir /mnt/raid1
➜  ~ sudo mount /dev/md0 /mnt/raid1/
➜  ~ sudo touch /mnt/raid1/lorem.txt  
➜  ~ sudo nano /mnt/raid1/lorem.txt 
➜  ~ cat /mnt/raid1/lorem.txt 
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras imperdiet mauris eget urna vehicula tristique non quis risus. Aliquam gravida eros vitae volutpat porta. Aenean sed ipsum maximus, venenatis ex ac, sodales velit. Aenean in purus velit. Fusce ultrices venenatis hendrerit. Nullam nec ipsum sit amet est dignissim consequat. In odio ex, finibus ac tempor ac, fringilla sed velit. Morbi vitae laoreet enim, eu suscipit magna.

➜  ~ sudo tail -1 /etc/fstab 
UUID=aedc9d01-f402-4ee7-be72-0a3b9289df6d /mnt/raid1 defaults 0 0

mdadm --detail --scan --verbose >> /etc/mdadm.conf
```
