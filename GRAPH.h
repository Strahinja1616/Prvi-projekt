#ifndef GRAPF_H_INCLUDED
#define GRAPF_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                 typedef struct node
                 {
                     struct node *up,*down,*next;
                     char info;
                 }NODE;

                 typedef struct
                 {
                     NODE *r,*f;
                 }RED;

                 NODE* create(char);
                 NODE* dodaj_cvor_u_vertikalnu_list(NODE*,char);
                 void dodaj_cvor_u_horizontalnu_listu(NODE*,char);
                 NODE* nadji_cvor_u_vertikalnoj_listi(NODE*,char);
                 NODE* nadji_cvor_u_horizontalnoj_listi(NODE*,char);
                 int** citaj_matricu(const char*,int*,char*);
                 void pisi_multilistu(NODE*);
                 void brisi_multilistu(NODE*);
//treba izbrisati na kraju multilistu
                 int is_queue_empty(RED);
                 void insert_queue(RED*,char);
                 char delete_queue(RED*);
                 void write_queue(RED);

                 void BFS(NODE*);

                 int isVisited(const char*,char);

#endif // GRAPF_H_INCLUDED
