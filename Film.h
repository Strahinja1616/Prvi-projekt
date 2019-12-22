#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
  // prosječna ocjena, naziv filma, godina objavljivanja, glumci, žanr

              typedef struct
              {
                  double ocjena;
                  int godina;
                  char naziv[11];
                  char glumci[11];
                  char zanr[6];
              }FILM;


              typedef struct
              {
                  char ime[20];
                  double trajanje;
              }ALGORITAM;

              double Vrati_Ocjenu();
              int Vrati_Godinu();
              void Vrati_String(char*,int);
              void Kreiraj_Film(FILM*);
              void Pisi_Filmove_U_Izvorni_Fajl(int);
              void Ucitaj_Niz(char*,int*,FILM**);
              void Pisi_Na_Konzolu(FILM*,int n);
              void Upisi_Sortiran_Niz_U_Datoteku(FILM*,int,char*);

              int Uporedi(FILM*,FILM*);//provera da ki prvi film ima manju ocenu
              int Uporedi_Veci(FILM*,FILM*);//provera da ki prvi film ima vecu ocenu
              int Provera_Jednakosti(FILM*,FILM*);//provera da li oba filma imaju vecu ocjenu

              void Selection_Sort(FILM*,int,int (*)(FILM*,FILM*));
              void Insertion_Sort(FILM*,int,int (*)(FILM*,FILM*));
              void Shell_Sort(FILM*,int,int (*)(FILM*,FILM*));
              void Quick_Sort(FILM*,int,int,int (*)(FILM*,FILM*),int (*)(FILM*,FILM*),int (*)(FILM*,FILM*));
              void Bubble_Sort(FILM*,int,int (*)(FILM*,FILM*));
              void Merge_Sort(FILM*,int,int,int (*)(FILM*,FILM*),int (*)(FILM*,FILM*),int (*)(FILM*,FILM*));
              void Heap_Sort(FILM*,int,int (*)(FILM*,FILM*),int (*)(FILM*,FILM*),int (*)(FILM*,FILM*));
              void Napravi_Heap(FILM*,int,int,int (*)(FILM*,FILM*),int (*)(FILM*,FILM*),int (*)(FILM*,FILM*));
              void Sortiraj(ALGORITAM*,int);
#endif // FILM_H_INCLUDED
