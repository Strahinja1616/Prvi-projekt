#include "GRAPH.h"

                 NODE* create(char info)
                 {
                     NODE *novi=(NODE *)malloc(sizeof(NODE));
                     novi->info=info;
                     novi->next=novi->up=novi->down=NULL;
                     return novi;
                 }



                 NODE* dodaj_cvor_u_vertikalnu_list(NODE *head,char info)
                 {

                     NODE *novi=create(info);
                     if(head==NULL) return novi;

                     NODE *pom=head;
                     while(head->down != NULL)
                        head=head->down;

                     head->down=novi;
                     novi->up=head;

                     return pom;
                 }


                 void dodaj_cvor_u_horizontalnu_listu(NODE *head,char info)
                 {
                     NODE *novi=create(info);
                     while(head->next != NULL) head=head->next;
                     head->next=novi;
                 }


                 NODE* nadji_cvor_u_vertikalnoj_listi(NODE *head,char key)
                 {
                    while(head != NULL)
                    {
                        if(head->info == key) return head;
                        head=head->down;
                    }

                    return head;
                 }



                 NODE* nadji_cvor_u_horizontalnoj_listi(NODE *head,char key)
                 {
                     while(head != NULL)
                     {
                         if(head->info == key) return head;
                         head=head->next;
                     }

                     return head;
                 }




                 int** citaj_matricu(const char *ime_datoteke,int *n,char *imena_cvorova)
                 {
                     FILE *fp=fopen(ime_datoteke,"r");
                     int dim,**niz,i,j;

                     fscanf(fp,"%d\n",&dim);
                     *n=dim;
                     fscanf(fp,"%s\n",imena_cvorova);

                     niz=(int **)malloc(dim*sizeof(int*));
                     for(i=0;i<dim;i++)
                        niz[i]=(int *)malloc(dim*sizeof(int));

                     for(i=0;i<dim;i++)
                     {
                         for(j=0;j<dim;j++)
                         {
                             fscanf(fp,"%d ",&niz[i][j]);
                         }
                           fscanf(fp,"\n");
                     }

                     return niz;
                 }


                 void pisi_multilistu(NODE *root)
                 {
                     for(;root != NULL;root=root->down)
                     {
                         printf("%c -> ",root->info);
                         NODE *q=root->next;

                         for(;q != NULL;q=q->next)
                         printf("%c ",q->info);

                         printf("\n");
                     }
                 }



                 int is_queue_empty(RED fifo)
                 {
                     return fifo.f==NULL;
                 }


                 void insert_queue(RED *fifo,char info)
                 {
                     NODE *novi=create(info);

                     if(fifo->f == NULL)
                     {
                         fifo->f=fifo->r=novi;
                     }
                     else
                     {
                         NODE *q=fifo->r;
                         q->next=novi;
                         fifo->r=novi;
                     }
                 }


                 char delete_queue(RED *fifo)
                 {
                     if(fifo->f == NULL) return '+';

                     NODE *z=fifo->f;
                     char rez=z->info;

                     if(fifo->f == fifo->r)
                        fifo->f=fifo->r=NULL;
                     else
                        fifo->f=z->next;

                     free(z);
                     return rez;
                 }

                  int isVisited(const char *rijec,char karakter)
                  {
                      int d=strlen(rijec),i;
                      for(i=0;i<d;i++)
                        if(rijec[i] == karakter)
                        return 1;

                      return 0;
                  }


                  void BFS(NODE *root)
                  {
                      if(root == NULL)  return;

                      RED fifo;
                      fifo.f=fifo.r=NULL;
                      char posjeta[50]={0},pom[2];
                      char processed_character;

                      pom[0]=root->info;  pom[1]=0;
                      strcat(posjeta,pom);
                      insert_queue(&fifo,root->info);

                      while(!is_queue_empty(fifo))
                      {

                           printf("\nSadrzaj reda:");
                           write_queue(fifo);
                           printf("\nPoseceni cvorovi:%s\n\n",posjeta);

                           processed_character=delete_queue(&fifo);
                           NODE *temp=nadji_cvor_u_vertikalnoj_listi(root,processed_character);

                           for(temp=temp->next;temp != NULL;temp=temp->next)
                               if(!isVisited(posjeta,temp->info))
                                {
                                    char processed_character=temp->info;
                                    pom[0]=processed_character;  pom[1]=0;
                                    strcat(posjeta,pom);
                                    insert_queue(&fifo,processed_character);
                                }

                      }

                  }


                  void write_queue(RED fifo)
                  {
                      for(;fifo.f != NULL; fifo.f=fifo.f->next)
                      {
                          printf("%c",fifo.f->info);
                      }
                  }



                  void brisi_multilistu(NODE *root)
                  {
                      while(root != NULL)
                      {
                            NODE *x=root;
                            root=root->down;
                            while(x != NULL)
                            {
                                NODE *y=x;
                                x=x->next;
                                free(y);
                            }
                      }

                  }


