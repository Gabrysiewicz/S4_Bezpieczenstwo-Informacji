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
file1   file11  file13  file15  file17  file19  file20  file22  file24  file26  file28  file3   file31  file33  file35  file37  file39  file40  file42  file44  file46  file48  file5  file7  file9
file10  file12  file14  file16  file18  file2   file21  file23  file25  file27  file29  file30  file32  file34  file36  file38  file4   file41  file43  file45  file47  file49  file6  file8

dane_nazwisko_copy:
file1   file11  file13  file15  file17  file19  file20  file22  file24  file26  file28  file3   file31  file33  file35  file37  file39  file40  file42  file44  file46  file48  file5  file7  file9
file10  file12  file14  file16  file18  file2   file21  file23  file25  file27  file29  file30  file32  file34  file36  file38  file4   file41  file43  file45  file47  file49  file6  file8
```

```
➜  Copies ls *
dane_nazwisko:
file1   file12  file15  file18  file20  file23  file26  file29  file31  file34  file37  file4   file42  file45  file48  file6  file9
file10  file13  file16  file19  file21  file24  file27  file3   file32  file35  file38  file40  file43  file46  file49  file7  img1.png
file11  file14  file17  file2   file22  file25  file28  file30  file33  file36  file39  file41  file44  file47  file5   file8  img2.jpeg

dane_nazwisko_copy:
file1   file12  file15  file18  file20  file23  file26  file29  file31  file34  file37  file4   file42  file45  file48  file6  file9
file10  file13  file16  file19  file21  file24  file27  file3   file32  file35  file38  file40  file43  file46  file49  file7  img3.jpeg
file11  file14  file17  file2   file22  file25  file28  file30  file33  file36  file39  file41  file44  file47  file5   file8  img4.jpeg

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
