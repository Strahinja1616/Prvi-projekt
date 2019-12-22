#include "Film.h"

              double Vrati_Ocjenu()
              {
                  return 0.01*(rand()%1000);
              }



              int Vrati_Godinu()
              {
                    return   rand()%2000;
              }


              void Vrati_String(char *rijec,int duzina)
              {
                  int i;
                  for(i=0;i<duzina-1;i++)
                    rijec[i]=97+rand()%26;
                  rijec[duzina-1]=0;
              }


              void Kreiraj_Film(FILM *f)
              {
                  f->godina=Vrati_Godinu();
                  f->ocjena=Vrati_Ocjenu();
                  Vrati_String(f->naziv,11);
                  Vrati_String(f->glumci,11);
                  Vrati_String(f->zanr,6);
              }


              void Pisi_Filmove_U_Izvorni_Fajl(int n)
              {
                  FILM temp;
                  int i;
                  FILE *fp=fopen("Film.txt","w");
                  if(fp==NULL) return;

                  fprintf(fp,"%d\n",n);
                  fprintf(fp,"%10s %10s %5s %6s %6s\n","NAZIV","GLUMCI","ZANR","OCJENA","GODINA");

                  for(i=0;i<n;i++)
                  {
                      Kreiraj_Film(&temp);
                      fprintf(fp,"%10s %10s %5s %5lf %5d\n",temp.naziv,temp.glumci,temp.zanr,temp.ocjena,temp.godina);
                  }

                  fclose(fp);
              }


              void Ucitaj_Niz(char *ime,int *duzina,FILM **film)
              {
                  FILE *fp=fopen(ime,"r");
                  if(fp==NULL)  return;
                  fscanf(fp,"%d\n",duzina);

                  char pom[100];
                  fgets(pom,100,fp);

                  FILM *niz=(FILM *)malloc(sizeof(FILM)*(*duzina));
                  *film=niz;
                  int i;

                  for(i=0;i < *duzina;i++)
                  {
                      fscanf(fp,"%s %s %s %lf %d\n",niz[i].naziv,niz[i].glumci,niz[i].zanr,&niz[i].ocjena,&niz[i].godina);
                  }

                  fclose(fp);
              }


              int Uporedi(FILM *f1,FILM *f2)
              {
                  return f1->ocjena < f2->ocjena;
              }


              void Pisi_Na_Konzolu(FILM *niz,int n)
              {
                  int i;
                  for(i=0;i<n;i++)
                  {
                      printf("%d %10s %10s %5s %5lf %5d\n",i+1,niz[i].naziv,niz[i].glumci,niz[i].zanr,niz[i].ocjena,niz[i].godina);
                  }
              }


              void Selection_Sort(FILM *niz,int n,int (*f)(FILM*,FILM*))
              {
                    int i,j;
                    for(i=0;i<n-1;i++)
                    {
                        int min=i;
                        for(j=i+1;j<n;j++)
                            if( (*f)(niz+min,niz+j) == 0)
                            min=j;
                        if(min != i)
                        {
                            FILM temp=niz[i];
                            niz[i]=niz[min];
                            niz[min]=temp;;
                        }

                    }

              }




              void Upisi_Sortiran_Niz_U_Datoteku(FILM *niz,int n,char *ime_fajla)
              {
                  FILE *fp=fopen(ime_fajla,"w");
                  if(fp == NULL)  return;
                  int i;

                  fprintf(fp,"%10s %10s %5s %6s %6s\n","NAZIV","GLUMCI","ZANR","OCJENA","GODINA");
                  for(i=0;i<n;i++)
                  {
                      fprintf(fp,"%10s %10s %5s %5lf %5d\n",niz[i].naziv,niz[i].glumci,niz[i].zanr,niz[i].ocjena,niz[i].godina);
                  }

                  fclose(fp);
              }



              void Insertion_Sort(FILM *niz,int n,int (*f)(FILM*,FILM*))
              {
                  int i,j;

                  for(i=1;i<n;i++)
                  {
                      FILM x=niz[i];
                      for(j=i; j>0 && (*f)(&x,&niz[j-1]) ;j--)
                        niz[j]=niz[j-1];
                        niz[j]=x;
                  }
              }



            void Shell_Sort(FILM *niz,int n,int (*f)(FILM*,FILM*))
            {
                int i,j,h;
                for(h=n/2;h>0;h/=2)
                {
                    for(i=h;i<n;i++)
                    {
                        FILM x=niz[i];
                        for(j=i;j >= h && (*f)(&x,&niz[j-h]);j-=h)
                            niz[j]=niz[j-h];
                        niz[j]=x;
                    }
                }
            }


                       int Provera_Jednakosti(FILM *f1,FILM *f2)
                       {
                           return f1->ocjena == f2->ocjena;
                       }


                       int Uporedi_Veci(FILM *f1,FILM *f2)
                       {
                           return f1->ocjena > f2->ocjena;
                       }



                       void Quick_Sort(FILM *niz,int start,int kraj,int (*vece)(FILM*,FILM*),int (*manje)(FILM*,FILM*),int (*jednako)(FILM*,FILM*))
                       {
                           if(start<kraj)
                           {
                               int i=start,j=kraj;
                               FILM pivot=niz[start];

                               while(i < j)
                               {
                                   while(i < j && ( (*jednako)(niz+i,&pivot) || (*manje)(niz+i,&pivot) ) )  i++;
                                   while( (*vece)(niz+j,&pivot) )  j--;

                                   if(i<j)
                                   {
                                       FILM temp=niz[i];
                                       niz[i]=niz[j];
                                       niz[j]=temp;
                                   }
                               }

                               niz[start]=niz[j];
                               niz[j]=pivot;

                               Quick_Sort(niz,start,j-1,vece,manje,jednako);
                               Quick_Sort(niz,j+1,kraj,vece,manje,jednako);
                           }
                       }


                       void Bubble_Sort(FILM *niz,int n,int (*veci)(FILM*,FILM*))
                       {
                           int i,j;
                           for(i=0;i<n-1;i++)
                           {
                               for(j=0;j<n-i-1;j++)
                                if( (*veci)(niz+j,niz+j+1) )
                               {
                                   FILM pom = niz[j];
                                   niz[j]=niz[j+1];
                                   niz[j+1]=pom;
                               }
                           }
                       }


                       void Merge_Sort(FILM* niz,int start,int kraj,int (*vece)(FILM*,FILM*),int (*manje)(FILM*,FILM*),int (*jednako)(FILM*,FILM*))
                       {
                           if(start < kraj)
                           {
                               int sredina=(start+kraj)/2;
                               int i,j,k,len=kraj-start+1;
                               FILM pom[len];

                               Merge_Sort(niz,start,sredina,vece,manje,jednako);
                               Merge_Sort(niz,sredina+1,kraj,vece,manje,jednako);

                               i=start;
                               j=sredina+1;
                               k=0;

                               while(i <= sredina && j <= kraj)
                                pom[k++] = (manje(niz+i,niz+j) || jednako(niz+i,niz+j))?niz[i++]:niz[j++];

                               while(i <= sredina) pom[k++]=niz[i++];
                               while(j <= kraj)    pom[k++]=niz[j++];

                               for(i=0;i<len;i++)
                                niz[start+i] = pom[i];
                           }
                       }


                       void Heap_Sort(FILM *niz,int n,int (*vece)(FILM*,FILM*),int (*manje)(FILM*,FILM*),int (*jednako)(FILM*,FILM*))
                       {
                           int i;
                           for(i=n/2-1;i>=0;i--)
		                   Napravi_Heap(niz,n,i,vece,manje,jednako);
	                       for(i=n-1;i>=0;i--)
                           {
		                   FILM pom=niz[0];
		                   niz[0]=niz[i];
                           niz[i]=pom;

                           Napravi_Heap(niz,i,0,vece,manje,jednako);
                           }
                       }



                      void Napravi_Heap(FILM *niz,int n,int i,int (*vece)(FILM*,FILM*),int (*manje)(FILM*,FILM*),int (*jednako)(FILM*,FILM*))
                       {
                           int otac=i;
                           int levi_sin=2*i+1;
	                       int desni_sin=2*i+2;

	                       if( levi_sin < n && vece(niz+levi_sin,niz+otac) )
                           otac=levi_sin;

                           if( desni_sin < n && vece(niz+desni_sin,niz+otac) )
                           otac=desni_sin;

                           if(otac != i)
                           {
                               FILM temp=niz[otac];
                               niz[otac]=niz[i];
                               niz[i]=temp;

                               Napravi_Heap(niz,n,otac,vece,manje,jednako);
                           }
                       }


                       void Sortiraj(ALGORITAM *niz,int n)
                       {
                           int i,j;
                           for(i=1;i<n;i++)
                           {
                               ALGORITAM pom=niz[i];

                               for(j=i;j>0 && niz[j-1].trajanje > pom.trajanje;j--)
                               niz[j]=niz[j-1];
                               niz[j]=pom;
                           }

                       }















