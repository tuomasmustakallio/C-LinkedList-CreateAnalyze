#Makefile
HT.exe: HT.o ali1.o ali2.o
    gcc ali1.o ali2.o HT.o -o HT.exe
HT.o: HT.c ali1.h ali2.h HT.h
    gcc HT.c -c -Wall -std=c99 -pedantic
ali1.o: ali1.c ali1.h HT.h
    gcc ali1.c -c -Wall -std=c99 -pedantic
ali2.o: ali2.c ali2.h paaohjelma.h
    gcc ali2.c -c -Wall -std=c99 -pedantic