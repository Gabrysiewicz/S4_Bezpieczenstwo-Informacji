<h1 align='center'>Kopia zapasowa</h1>

<h3> P.7.1.Udokumentuj utworzenie lokalnej kopii zapasowej. Porównaj zawartość katalogów.
Możesz w tym celu użyć polecenia diff. Wyjaśnij, co się stało podczas tworzenia kopii
i dlaczego. </h3>
<h3>Grsync</h3>
<img src='https://github.com/Gabrysiewicz/BI-Szyfry/blob/copy/grsync.png' >

```
.
├── dane_nazwisko
│   ├── plik1
│   ├── plik10
│   ├── plik11
│   ├── plik12
│   ├── plik13
│   ├── plik14
│   ├── plik15
│   ├── plik16
│   ├── plik17
│   ├── plik18
│   ├── plik19
│   ├── plik2
│   ├── plik20
│   ├── plik21
│   ├── plik22
│   ├── plik23
│   ├── plik24
│   ├── plik25
│   ├── plik26
│   ├── plik27
│   ├── plik28
│   ├── plik29
│   ├── plik3
│   ├── plik30
│   ├── plik31
│   ├── plik32
│   ├── plik33
│   ├── plik34
│   ├── plik35
│   ├── plik36
│   ├── plik37
│   ├── plik38
│   ├── plik39
│   ├── plik4
│   ├── plik40
│   ├── plik41
│   ├── plik42
│   ├── plik43
│   ├── plik44
│   ├── plik45
│   ├── plik46
│   ├── plik47
│   ├── plik48
│   ├── plik49
│   ├── plik5
│   ├── plik50
│   ├── plik6
│   ├── plik7
│   ├── plik8
│   └── plik9
└── dane_nazwisko_kopia
    └── dane_nazwisko
        ├── plik1
        ├── plik10
        ├── plik11
        ├── plik12
        ├── plik13
        ├── plik14
        ├── plik15
        ├── plik16
        ├── plik17
        ├── plik18
        ├── plik19
        ├── plik2
        ├── plik20
        ├── plik21
        ├── plik22
        ├── plik23
        ├── plik24
        ├── plik25
        ├── plik26
        ├── plik27
        ├── plik28
        ├── plik29
        ├── plik3
        ├── plik30
        ├── plik31
        ├── plik32
        ├── plik33
        ├── plik34
        ├── plik35
        ├── plik36
        ├── plik37
        ├── plik38
        ├── plik39
        ├── plik4
        ├── plik40
        ├── plik41
        ├── plik42
        ├── plik43
        ├── plik44
        ├── plik45
        ├── plik46
        ├── plik47
        ├── plik48
        ├── plik49
        ├── plik5
        ├── plik50
        ├── plik6
        ├── plik7
        ├── plik8
        └── plik9
```

<h3> Rsync </h3>

```
student@LabVM:~/KopieZapasowe/rsync$ rsync -r dane_nazwisko/ dane_nazwisko_kopia/
student@LabVM:~/KopieZapasowe/rsync$ ls dane_nazwisko_kopia/
imag2.jpeg  plik10  plik13  plik16  plik19  plik21  plik24  plik27  plik3   plik32  plik35  plik38  plik40  plik43  plik46  plik49  plik7
img1.jpeg   plik11  plik14  plik17  plik2   plik22  plik25  plik28  plik30  plik33  plik36  plik39  plik41  plik44  plik47  plik5   plik8
plik1       plik12  plik15  plik18  plik20  plik23  plik26  plik29  plik31  plik34  plik37  plik4   plik42  plik45  plik48  plik6   plik9
```

```
student@LabVM:~/KopieZapasowe/rsync$ ls *
dane_nazwisko:
imag2.jpeg  plik10  plik13  plik16  plik19  plik21  plik24  plik27  plik3   plik32  plik35  plik38  plik40  plik43  plik46  plik49  plik7
img1.jpeg   plik11  plik14  plik17  plik2   plik22  plik25  plik28  plik30  plik33  plik36  plik39  plik41  plik44  plik47  plik5   plik8
plik1       plik12  plik15  plik18  plik20  plik23  plik26  plik29  plik31  plik34  plik37  plik4   plik42  plik45  plik48  plik6   plik9

dane_nazwisko_kopia:
img3.jpeg  plik10  plik13  plik16  plik19  plik21  plik24  plik27  plik3   plik32  plik35  plik38  plik40  plik43  plik46  plik49  plik7
img4.jpeg  plik11  plik14  plik17  plik2   plik22  plik25  plik28  plik30  plik33  plik36  plik39  plik41  plik44  plik47  plik5   plik8
plik1      plik12  plik15  plik18  plik20  plik23  plik26  plik29  plik31  plik34  plik37  plik4   plik42  plik45  plik48  plik6   plik9

student@LabVM:~/KopieZapasowe/rsync$ rsync -av --delete dane_nazwisko/ dane_nazwisko_kopia/
sending incremental file list
deleting img4.jpeg
deleting img3.jpeg
./
imag2.jpeg
img1.jpeg
plik1
plik10
plik11
plik12
plik13
plik14
plik15
plik16
plik17
plik18
plik19
plik2
plik20
plik21
plik22
plik23
plik24
plik25
plik26
plik27
plik28
plik29
plik3
plik30
plik31
plik32
plik33
plik34
plik35
plik36
plik37
plik38
plik39
plik4
plik40
plik41
plik42
plik43
plik44
plik45
plik46
plik47
plik48
plik49
plik5
plik6
plik7
plik8
plik9

sent 17,336 bytes  received 1,014 bytes  36,700.00 bytes/sec
total size is 14,529  speedup is 0.79
```

Przy pomocy polecenia rsync opcja 
```
-a, --append     append data onto shorter files
 - dokleja zmieniona zawarosc
-v, --verbose    increase verbosity 
-delete         delete extraneous files from destination dirs
                - usuwa nadprogramowe pliki 
```
