/*Ulančanom reprezentacijom realizovati usmjereni netežinski graf na
osnovu matrične reprezentacije koja se učitava iz tekstualnog fajla.
Graf obići BFS metodom, pri čemu se za svaki korak BFS algoritma
ispisuje niz sa čvorovima koji se obilaze u sljedećim koracima,
kao i niz sa čvorovima koji su bili posjećeni. */
#include "GRAPH.h"

                 int main(int argc,char **argv)
                 {

                      int i,j,n,**niz;
                      char nazivi_cvorova[20];
                      NODE *root=NULL;

                      niz=citaj_matricu(argv[1],&n,nazivi_cvorova);

                      for(i=0;i < n;i++)
                        root=dodaj_cvor_u_vertikalnu_list(root,nazivi_cvorova[i]);

                      for(i=0;i<n;i++)
                      {
                           NODE *current=nadji_cvor_u_vertikalnoj_listi(root,nazivi_cvorova[i]);

                           for(j=0;j<n;j++)
                           {
                                   if(niz[i][j]==1)
                                   dodaj_cvor_u_horizontalnu_listu(current,nazivi_cvorova[j]);
                           }

                      }

                       pisi_multilistu(root);
                       BFS(root);
                       brisi_multilistu(root);
                       root=NULL;
                      return 0;
                 }
