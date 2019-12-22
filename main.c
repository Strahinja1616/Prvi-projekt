#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Film.h"
int main()
{
        Pisi_Filmove_U_Izvorni_Fajl(10000);
        FILM *niz=NULL;
        int n,i;
        clock_t start,end;
        ALGORITAM arr[7];

        Ucitaj_Niz("Film.txt",&n,&niz);
        start=clock();
        Heap_Sort(niz,n,Uporedi_Veci,Uporedi,Provera_Jednakosti);
        end=clock();
        strcpy(arr[0].ime,"Heap-Sort");
        arr[0].trajanje = (double)( ((double)(end-start))/CLOCKS_PER_SEC );
        Upisi_Sortiran_Niz_U_Datoteku(niz,n,"Heap_Sort.txt");


        Ucitaj_Niz("Film.txt",&n,&niz);
        start=clock();
        Quick_Sort(niz,0,n-1,Uporedi_Veci,Uporedi,Provera_Jednakosti);
        end=clock();
        strcpy(arr[1].ime,"Quick-Sort");
        arr[1].trajanje = (double)( ((double)(end-start))/CLOCKS_PER_SEC );
        Upisi_Sortiran_Niz_U_Datoteku(niz,n,"Quick_Sort.txt");


        Ucitaj_Niz("Film.txt",&n,&niz);
        start=clock();
        Merge_Sort(niz,0,n-1,Uporedi_Veci,Uporedi,Provera_Jednakosti);
        end=clock();
        strcpy(arr[2].ime,"Merge-Sort");
        arr[2].trajanje = (double)( ((double)(end-start))/CLOCKS_PER_SEC );
        Upisi_Sortiran_Niz_U_Datoteku(niz,n,"Merge_Sort.txt");

        Ucitaj_Niz("Film.txt",&n,&niz);
        start=clock();
        Shell_Sort(niz,n,Uporedi);
        end=clock();
        strcpy(arr[3].ime,"Shell-Sort");
        arr[3].trajanje = (double)( ((double)(end-start))/CLOCKS_PER_SEC );
        Upisi_Sortiran_Niz_U_Datoteku(niz,n,"Shell_Sort.txt");

        Ucitaj_Niz("Film.txt",&n,&niz);
        start=clock();
        Selection_Sort(niz,n,Uporedi);
        end=clock();
        strcpy(arr[4].ime,"Selection-Sort");
        arr[4].trajanje = (double)( ((double)(end-start))/CLOCKS_PER_SEC );
        Upisi_Sortiran_Niz_U_Datoteku(niz,n,"Selection_Sort.txt");

        Ucitaj_Niz("Film.txt",&n,&niz);
        start=clock();
        Insertion_Sort(niz,n,Uporedi);
        end=clock();
        strcpy(arr[5].ime,"Insertion-Sort");
        arr[5].trajanje = (double)( ((double)(end-start))/CLOCKS_PER_SEC );
        Upisi_Sortiran_Niz_U_Datoteku(niz,n,"Insertion_Sort.txt");


        Ucitaj_Niz("Film.txt",&n,&niz);
        start=clock();
        Bubble_Sort(niz,n,Uporedi_Veci);
        end=clock();
        strcpy(arr[6].ime,"Bubble-Sort");
        arr[6].trajanje = (double)( ((double)(end-start))/CLOCKS_PER_SEC );
        Upisi_Sortiran_Niz_U_Datoteku(niz,n,"Bubble_Sort.txt");

        Sortiraj(arr,7);
        for(i=0;i<7;i++)
            printf("%s - %lf\n",arr[i].ime,arr[i].trajanje);

        free(niz);
        niz=NULL;
    return 0;
}
