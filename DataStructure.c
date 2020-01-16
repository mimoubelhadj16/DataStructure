#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Element {
    char info[10];
    struct Element *svt;
} Element, *list;
 void affiche_liste(list l)
  {
      while(l!=NULL)
      {
          puts(l->info);
         l=l->svt;
      }

  }
  void viderbuffer()
  {
      int c=0;
      while(c!='\n'&&c!=EOF)
      {
          c=getchar();
      }
  }
list TriListe_c(list la)
{// ici on va ranger les elemants dans l'ordre croisssant avant de les afficher...
    int nbcmp=0,nbprm=0,etp=0;
   list p,q;
   char  a[10];

   p=la;

   while(p->svt!=NULL)
   {
        q=p->svt;
        while(q!= NULL)
        {
            nbcmp++;
         if (strcmp(p->info,q->info)>0)
         {
              strcpy(a,p->info);
              strcpy(p->info,q->info);
              strcpy(q->info,a);
              nbprm++;
               printf("etape n:%d\n",etp+1);
               etp++;
               affiche_liste(la);

         }
        q=q->svt;
       }
        p=p->svt;
    }
              printf("nbr de cemparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
        return la; }
list TriListe_d(list la)
{// ici on va ranger les elemants dans l'ordre croisssant avant de les afficher...
    int nbcmp=0,nbprm=0,etp=0;
   list p,q;
   char  a[10];

   p=la;

   while(p->svt!=NULL)
   {
        q=p->svt;
        while(q!= NULL)
        {
            nbcmp++;
         if (strcmp(p->info,q->info)<0)
         {
              strcpy(a,p->info);
              strcpy(p->info,q->info);
              strcpy(q->info,a);
              nbprm++;
               printf("etape n:%d\n",etp+1);
               etp++;

               affiche_liste(la);

         }
        q=q->svt;
       }
        p=p->svt;
    }
       printf("nbr de cemparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
        return la; }

list CreatList_FIFO(int n) {
    list tete = NULL, p = NULL;
    char x[10]; int i;
        gets(x);


        tete = (list)malloc(sizeof(Element));
        if (tete == NULL) {
            printf("Erreur allocation dynamique\n");
            exit(EXIT_FAILURE);
        }
        strcpy(tete->info,x);
        p = tete;
         for(i=0;i<n;i++)
         {
             gets(x);

            p->svt = (list)malloc(sizeof(Element));
            if (p->svt == NULL) {
                printf("Erreur allocation dynamique");
                exit(EXIT_FAILURE);
            }
            p = p->svt;
            strcpy(p->info,x);

         }
        p->svt = NULL;

    return tete;
}

void Tri_supp_croissant (int n , int *t)
{
    int res[n],i,j,cmp=0;
    for(i=0;i<n;i++)
    {
        cmp=0;
        for(j=0;j<n;j++)
        {
            if(t[j]<t[i])
                cmp++;
        }
        res[cmp]=t[i];
    }
     for(i=0;i<n;i++)
     {
         t[i]=res[i];
     }
}
void Tri_supp_decroissant (int n , int *t)
{
    int res[n],i,j,cmp=0;
    for(i=0;i<n;i++)
    {
        cmp=0;
        for(j=0;j<n;j++)
        {
            if(t[j]>t[i])
                cmp++;
        }
        res[cmp]=t[i];
    }
     for(i=0;i<n;i++)
     {
         t[i]=res[i];
     }
}

void Tri_insertion(int n,int *tab)
{
  int i,var,j,nbcmp=0,nbprm=0;
  for ( i = 0; i < n; i++)
  {
      var=tab[i];
      j=i-1;
      while (j>=0 && tab[j]>var)
      {
          tab[j+1]=tab[j];
          j--;
          nbcmp++;
      }
      tab[j+1]=var;
      nbprm++;
  }
  printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
}
void Tri_bulle (int n,int *tab)
{
    int esc,i,nbcmp=0,nbprm=0;
    do
    {
        esc=0;
         for(i=0;i<n-1;i++)
         {
             if (tab[i]>tab[i+1])
             {
                 nbcmp++;
                 int temp ;
                 temp=tab[i];
                 tab[i]=tab[i+1];
                 tab[i+1]=temp;
                 esc++;
                 nbprm++;
             }

         }
    }while(esc>0);
     printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
}
void Tri_selection(int n, int *tab)
{
    int i,max,posmax,nbcmp=0,nbprm=0;
 while (n>0)
 {
     max=tab[0];
     posmax=0;

      for(i=0;i<n;i++)
      {
          if (tab[i]>max)
          {
              nbcmp++;
             max=tab[i];
             posmax=i;
          }
      }
       for (i=posmax;i<n;i++)
       {
           tab[i]=tab[i+1];
           nbprm++;
       }
       tab[n-1]=max;
       n--;
 }
    printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);

}
void Tri_insertion_decroissant(int n,int *tab)
{
  int i,var,j,nbcmp=0,nbprm=0;
  for ( i = 0; i < n; i++)
  {
      var=tab[i];
      j=i-1;
      while (j>=0 && tab[j]<var)
      {
          tab[j+1]=tab[j];
          j--;
          nbcmp++;
      }
      tab[j+1]=var;
      nbprm++;
  }
   printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);

}
void Tri_selection_decroissant(int n, int *tab)
{
    int i,min,posmax,nbcmp=0,nbprm=0;
 while (n>0)
 {
     min=tab[0];
     posmax=0;

      for(i=0;i<n;i++)
      {
          if (tab[i]<min)
          {
              nbcmp++;
             min=tab[i];
             posmax=i;
          }
      }
       for (i=posmax;i<n;i++)
       {
           tab[i]=tab[i+1];
           nbprm++;
       }
       tab[n-1]=min;
       n--;
 }
  printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);

}
void Tri_bulle_decroissant (int n,int *tab)
{
    int esc,i;
    do
    {
        esc=0;
         for(i=0;i<n-1;i++)
         {
             if (tab[i]<tab[i+1])
             {
                 int temp ;
                 temp=tab[i];
                 tab[i]=tab[i+1];
                 tab[i+1]=temp;
                 esc++;
             }
         }
    }while(esc>0);
}
void TriMat_insertion_ligne(int ligne,int colon,int mat[ligne][colon])
  {
      int i,j,nbcmp=0,nbprm=0;

       for(i=0;i<ligne;i++)
       {
           Tri_insertion(colon,mat[i]);
       }

      for(i=0;i<ligne;i++)
      {
          for(j=0;j<colon;j++)
          {
              printf("%d ",mat[i][j]);

          }
          printf("\n");
      }
  }
 void TriMat_insertion(int ligne,int colon,int mat[ligne][colon])
  {
      int i,j,k=0;
       int  t[ligne*colon];
       for(i=0;i<ligne;i++)
       {
           for (j=0;j<colon;j++)
           {
               t[k]=mat[i][j];
               k++;
           }
       }
       Tri_insertion(k,t);

      for(k=0;k<ligne*colon;k++)
      {
          printf("%d ",t[k]);
          if (k==ligne-1)
          {
              printf("\n");
          }

      }
    printf("\n");
  }
  void TriMat_selection_ligne(int ligne,int colon,int mat[ligne][colon])
  {
       int i,j;

       for(i=0;i<ligne;i++)
       {
           Tri_selection(colon,mat[i]);
       }

      for(i=0;i<ligne;i++)
      {
          for(j=0;j<colon;j++)
          {
              printf("%d ",mat[i][j]);
          }
          printf("\n");
      }
  }
   void TriMat_selection(int ligne,int colon,int mat[ligne][colon])
   {
       int i,j,k=0;
       int  t[ligne*colon];
       for(i=0;i<ligne;i++)
       {
           for (j=0;j<colon;j++)
           {
               t[k]=mat[i][j];
               k++;
           }
       }
       Tri_selection(k,t);

      for(k=0;k<ligne*colon;k++)
      {
          printf("%d ",t[k]);
          if (k==ligne-1)
          {
              printf("\n");
          }

      }
    printf("\n");
   }
   void TriMat_bulle_ligne(int ligne,int colon,int mat[ligne][colon])
   {
      int i,j;

       for(i=0;i<ligne;i++)
       {
           Tri_bulle(colon,mat[i]);
       }

      for(i=0;i<ligne;i++)
      {
          for(j=0;j<colon;j++)
          {
              printf("%d ",mat[i][j]);
          }
          printf("\n");
      }
   }
  void TriMat_bulle(int ligne,int colon,int mat[ligne][colon])
  {
      int i,j,k=0;
       int  t[ligne*colon];
       for(i=0;i<ligne;i++)
       {
           for (j=0;j<colon;j++)
           {
               t[k]=mat[i][j];
               k++;
           }
       }
       Tri_bulle(k,t);

      for(k=0;k<ligne*colon;k++)
      {
          printf("%d ",t[k]);
          if (k==ligne-1)
          {
              printf("\n");
          }

      }
    printf("\n");
  }
  void TriMat_insertion_ligne_decroissant(int ligne,int colon,int mat[ligne][colon])
   {

      int i,j;

       for(i=0;i<ligne;i++)
       {
           Tri_insertion_decroissant(colon,mat[i]);
       }

      for(i=0;i<ligne;i++)
      {
          for(j=0;j<colon;j++)
          {
              printf("%d ",mat[i][j]);
          }
          printf("\n");
      }
   }
 void  TriMat_selection_ligne_decroissant(int ligne,int colon,int mat[ligne][colon])
   {

      int i,j;

       for(i=0;i<ligne;i++)
       {
           Tri_selection_decroissant(colon,mat[i]);
       }

      for(i=0;i<ligne;i++)
      {
          for(j=0;j<colon;j++)
          {
              printf("%d ",mat[i][j]);
          }
          printf("\n");
      }
   }
 void  TriMat_bulle_ligne_decroissant(int ligne,int colon,int mat[ligne][colon])
   {

      int i,j;

       for(i=0;i<ligne;i++)
       {
           Tri_bulle_decroissant(colon,mat[i]);
       }

      for(i=0;i<ligne;i++)
      {
          for(j=0;j<colon;j++)
          {
              printf("%d ",mat[i][j]);
          }
          printf("\n");
      }
   }
    void TriMat_insertion_decroissant(int ligne,int colon,int mat[ligne][colon])
    {
         int i,j,k=0;
       int  t[ligne*colon];
       for(i=0;i<ligne;i++)
       {
           for (j=0;j<colon;j++)
           {
               t[k]=mat[i][j];
               k++;
           }
       }
       Tri_insertion_decroissant(k,t);

      for(k=0;k<ligne*colon;k++)
      {
          printf("%d ",t[k]);
          if (k==ligne-1)
          {
              printf("\n");
          }

      }
    printf("\n");
    }
    void TriMat_selection_decroissant(int ligne,int colon,int mat[ligne][colon])
    {
        int i,j,k=0;
       int  t[ligne*colon];
       for(i=0;i<ligne;i++)
       {
           for (j=0;j<colon;j++)
           {
               t[k]=mat[i][j];
               k++;
           }
       }
       Tri_selection_decroissant(k,t);

      for(k=0;k<ligne*colon;k++)
      {
          printf("%d ",t[k]);
          if (k==ligne-1)
          {
              printf("\n");
          }

      }
    printf("\n");

    }

  void TriMat_bulle_decroisant(int ligne,int colon,int mat[ligne][colon])
  {
      int i,j,k=0;
       int  t[ligne*colon];
       for(i=0;i<ligne;i++)
       {
           for (j=0;j<colon;j++)
           {
               t[k]=mat[i][j];
               k++;
           }
       }
       Tri_bulle_decroissant(k,t);

      for(k=0;k<ligne*colon;k++)
      {
          printf("%d ",t[k]);
          if (k==ligne-1)
          {
              printf("\n");
          }

      }
    printf("\n");
  }
void TriMat_chaine_insrtion_croissant(int nbrmot,char **mat)
   {
      int i,nbcmp=0,nbprm=0,etp=0;
       char temp[20];
       for(i=0;i<nbrmot-1;i++)
       {
        if(strcmp(mat[i],mat[i+1])>0)
       {
           printf("etape n %d:\n",etp);

         strcpy(temp,mat[i]);
         puts(temp);
         strcpy(mat[i],mat[i+1]);
          puts(mat[i]);
         strcpy(mat[i+1],temp);
         nbprm++;

       }
         puts(mat[i+1]);

          etp++;
          nbcmp++;

       }
         printf("\n\n");
        printf("matrice apres le traitement croissant:\n");
       for(i=0;i<nbrmot;i++)
            {
                puts(mat[i]);
            }
        printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
   }
void TriMat_chaine_selection_croissant(int nbrmot,int **mat)
   {
int i,nbcmp=0,nbprm=0,etp=0;
       char temp[20];
       for(i=0;i<nbrmot-1;i++)
       {
        if(strcmp(mat[i],mat[i+1])>0)
       {
           printf("etape n %d:\n",etp);

         strcpy(temp,mat[i]);
         puts(temp);
         strcpy(mat[i],mat[i+1]);
          puts(mat[i]);
         strcpy(mat[i+1],temp);
         nbprm++;

       }
         puts(mat[i+1]);

          etp++;
          nbcmp++;

       }
         printf("\n\n");
        printf("matrice apres le traitement croissant:\n");
       for(i=0;i<nbrmot;i++)
            {
                puts(mat[i]);
            }
        printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
   }
void TriMat_chaine_bulle_croissant(int nbrmot,int **mat)
{
int i,nbcmp=0,nbprm=0,etp=0;
       char temp[20];
       for(i=0;i<nbrmot-1;i++)
       {
        if(strcmp(mat[i],mat[i+1])>0)
       {
           printf("etape n %d:\n",etp);

         strcpy(temp,mat[i]);
         puts(temp);
         strcpy(mat[i],mat[i+1]);
          puts(mat[i]);
         strcpy(mat[i+1],temp);
         nbprm++;

       }
         puts(mat[i+1]);

          etp++;
          nbcmp++;

       }
         printf("\n\n");
        printf("matrice apres le traitement croissant:\n");
       for(i=0;i<nbrmot;i++)
            {
                puts(mat[i]);
            }
        printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
}
TriMat_chaine_insrtion_decroissant(int nbrmot,int **mat)
{

int i,nbcmp=0,nbprm=0,etp=0;
       char temp[20];
       for(i=0;i<nbrmot-1;i++)
       {
        if(strcmp(mat[i],mat[i+1])<0)
       {
           printf("etape n %d:\n",etp);

         strcpy(temp,mat[i]);
         puts(temp);
         strcpy(mat[i],mat[i+1]);
          puts(mat[i]);
         strcpy(mat[i+1],temp);
         nbprm++;

       }
         puts(mat[i+1]);

          etp++;
          nbcmp++;

       }
         printf("\n\n");
        printf("matrice apres le traitement decroissant:\n");
       for(i=0;i<nbrmot;i++)
            {
                puts(mat[i]);
            }
        printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
}
TriMat_chaine_selection_decroissant(int nbrmot,int **mat)
{

int i,nbcmp=0,nbprm=0,etp=0;
       char temp[20];
       for(i=0;i<nbrmot-1;i++)
       {
        if(strcmp(mat[i],mat[i+1])<0)
       {
           printf("etape n %d:\n",etp);

         strcpy(temp,mat[i]);
         puts(temp);
         strcpy(mat[i],mat[i+1]);
          puts(mat[i]);
         strcpy(mat[i+1],temp);
         nbprm++;

       }
         puts(mat[i+1]);

          etp++;
          nbcmp++;

       }
         printf("\n\n");
        printf("matrice apres le traitement decroissant:\n");
       for(i=0;i<nbrmot;i++)
            {
                puts(mat[i]);
            }
        printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
}
TriMat_chaine_bulle_decroissant(int nbrmot,int **mat)
{

int i,nbcmp=0,nbprm=0,etp=0;
       char temp[20];
       for(i=0;i<nbrmot-1;i++)
       {
        if(strcmp(mat[i],mat[i+1])<0)
       {
           printf("etape n %d:\n",etp);

         strcpy(temp,mat[i]);
         puts(temp);
         strcpy(mat[i],mat[i+1]);
          puts(mat[i]);
         strcpy(mat[i+1],temp);
         nbprm++;

       }
         puts(mat[i+1]);

          etp++;
          nbcmp++;

       }
         printf("\n\n");
        printf("matrice apres le traitement decroissant:\n");
       for(i=0;i<nbrmot;i++)
            {
                puts(mat[i]);
            }
        printf("nbr de comparaison:%d , nbr de permutation:%d\n",nbcmp,nbprm);
}
  int main ()
  {
      int nbr_lignes,nbr_colonnes,choix_type,choix_mode,nbr_elemntsTab,nbr_elemntsList,nb_colonne,choix_deTri,nb_ligne,nbr_de_mots,i,j,n;
      char entier_chaine,direct_parligne,choix_supp;
      int T[1000],Mat[10][10];
      char **M;
      list une_liste;
                    printf("\t\t\tUNIVERSITE DES SCIENCES ET DE LA TECHNOLOGIE HOUARI BOUMEDIENE\n ");
                     printf(" Travail realise par:\n");
                      printf("BELHADJ Abderrahmane\nBENSERADJ Mehdi\n");
                      printf("\n\n\t\t\t\tDEVOIR d'Algorithmique\n");
                      printf("\n\n");

      printf("\t................................Bienvenue....................................\n\n");
       printf("\t\t   -------------veuillez choisir dans ce Menu -------------\n\n\n");
       printf("               _______________________MENU______________________________\n\n");
       printf("         \t\t   Traitements des TABLEAUX inserer 1 \n");
       printf("         \t\t   Traitements des MATRICES inserer 2 \n");
       printf("      \t\t   Traitements des LISTES-CHAINNEES chainees inserer 3 \n");
       printf("               _______________________________________________________\n");
            do{
               printf("\nchoix:");
               scanf("%d",&choix_type);
                if (choix_type<0 || choix_type>3)
                  printf("\t<!> ce cas ne figure pas dans la liste.reesayez svp!");
              }while(choix_type<0 || choix_type>3) ;
        switch(choix_type)
        {
          case 1://user a choisi traitement des tableax
                printf("\tok vous avez choisi le traitement de tri d'un tableau.\n");
                  do{
                      printf("veuillez choisir le type de traitement(saisissez le numero de votre choix dans la liste suivante) :\n");
                      printf("\t***1.tri par insrtion***\n");
                      printf("\t***2.tri par selection***\n");
                      printf("\t***3.tri par bulle***\n");
                      scanf("%d",&choix_deTri);
                        if(choix_deTri<1 || choix_deTri>3)
                          printf("<!>Ce numero ne figure pas dans la liste!!\n ");
                    }while((choix_deTri<1) ||(choix_deTri>3));
                       printf("faire le traitement en mode 'croissant(0)' ou 'decroissant(1)' ?:\n ");
                        scanf("%d",&choix_mode);
                         while(choix_mode>1|| choix_mode<0)
                         {
                             printf("svp  1 ou 0 :");
                             scanf("%d",&choix_mode);
                         }

                       switch(choix_mode)
                        {
                          case 0 :// traitement tableaux en croissant
                                   printf("mode croissant\n");

                             printf("ok donc donnez le nombre d'elements du tableau et les valeurs\n");
                             printf("nombre d'elements:");
                              scanf("%d",&nbr_elemntsTab);
                               printf("inserez les valeurs:\n");
                               for(i=0;i<nbr_elemntsTab;i++)
                               {
                                   printf("T[%d]:",i);
                                   scanf("%d",&T[i]);
                               }
                                if (choix_deTri==1 ) //traitement tableaux en croissant en fonction insertion
                                {

                                    Tri_insertion(nbr_elemntsTab,T);
                                    for ( i = 0; i < nbr_elemntsTab; i++)
                                    {
                                        printf("%d\t",T[i]);
                                    }

                                }
                                 else if(choix_deTri==2)//traitement tableaux en croissant en fonction selection
                                    {
                                    Tri_selection(nbr_elemntsTab,T);
                                      for ( i = 0; i < nbr_elemntsTab; i++)
                                    {
                                        printf("%d\t",T[i]);
                                    }}
                                    else if (choix_deTri==3)//traitement tableaux en croissant en fonction bulle
                                     {
                                        Tri_bulle(nbr_elemntsTab,T);
                                         for ( i = 0; i < nbr_elemntsTab; i++)
                                         {
                                           printf("%d\t",T[i]);
                                         }}

                                 printf("\n");
                                 break;
                          case 1://traitement tableaux en decroissant
                                 printf("mode decroissant\n");

                                       printf("ok donc donnez le nombre d'elements du tableau et les valeurs\n");
                                       printf("nombre d'elements:");
                                       scanf("%d",&nbr_elemntsTab);
                                       printf("inserez les valeurs:\n");
                                        for(i=0;i<nbr_elemntsTab;i++)
                                       {
                                          printf("T[%d]:",i);
                                          scanf("%d",&T[i]);
                                        }
                                          if (choix_deTri==1 )//traitement tableaux en decroissant en fonction insertion
                                         {
                                           Tri_insertion_decroissant(nbr_elemntsTab,T);
                                           for ( i = 0; i < nbr_elemntsTab; i++)
                                           {
                                             printf("%d\t",T[i]);
                                           }
                                        }


                                    else if(choix_deTri==2)//traitement tableaux en decroissant en fonction selection
                                    {
                                    Tri_selection_decroissant(nbr_elemntsTab,T);
                                      for ( i = 0; i < nbr_elemntsTab; i++)
                                    {
                                        printf("%d\t",T[i]);
                                    }
                                    }
                                    else if (choix_deTri==3)//traitement tableaux en decroissant en fonction bulle
                                     {
                                        Tri_bulle_decroissant(nbr_elemntsTab,T);
                                         for ( i = 0; i < nbr_elemntsTab; i++)
                                         {
                                           printf("%d\t",T[i]);
                                         }

                                     printf("\n");
                                    }

                      printf("\n");
                     break;}
                     break;
            case 2: // traitement de matrices ...
                     printf("\tok vous avez choisi le traitement d'une matrice.\n");
                     printf("faire le traitement sur les entiers (e/E) ou chaine de caracteres (c/C)\n");
                        do{
                        scanf("%c",&entier_chaine);

                             while(entier_chaine!='e'&&entier_chaine!='E'&&entier_chaine!='c'&&entier_chaine!='C')
                             {     if(entier_chaine!='e'&&entier_chaine!='E'&&entier_chaine!='c'&&entier_chaine!='C')

                                   {
                                       printf("tapez (e/E) ou (c/C svp):");
                                   }
                                  scanf("%c",&entier_chaine);
                             }
                         }while(entier_chaine!='e'&&entier_chaine!='E'&&entier_chaine!='c'&&entier_chaine!='C');

                             printf("vous voulez le traitement ligne par ligne (l) ou direct(d):\n");
                              scanf("%c",&direct_parligne);
                                  while(direct_parligne!='l'&&direct_parligne!='d')
                                      {
                                          printf("tapez 'l' ou 'd' svp:");
                                          scanf("%c",&direct_parligne);
                                      }
                     do{// choix de la fonction de traitement des matrices ...
                      printf("veuillez choisir le type de traitement(saisissez le numero de votre choix dans la liste suivante) :\n");
                      printf("\t***1.tri de matrices par insrtion***\n");
                      printf("\t***2.tri de matrices par selection***\n");
                      printf("\t***3.tri de matrices par bulle***\n");
                      scanf("%d",&choix_deTri);
                        if(choix_deTri<1 || choix_deTri>3)
                          printf("<!>Ce cas ne figure pas dans la liste!!\n ");
                    }while((choix_deTri<1) ||(choix_deTri>3));
                       printf("faire le traitement en mode 'croissant(0)' ou 'decroissant(1)' ?:\n ");
                        scanf("%d",&choix_mode);
                         while(choix_mode>1|| choix_mode<0)
                         {
                             printf("svp 1 ou 0 :");
                             scanf("%d",&choix_mode);
                         }

                       switch(choix_mode)
                        {
                          case 0 :// traitemnt croissant des matrices
                                    printf("\t mode croissant\n");
                                     if((entier_chaine=='e'|| entier_chaine=='E'))// si le choix etaitt matrices entiers ..

                            {

                                    printf("ok donc donnez le nombre de ligne et colonnes de la matrices:\n");
                                    printf("nombre ligne:");
                                    scanf("%d",&nbr_lignes);
                                    printf("nombre de colonnes:");
                                    scanf("%d",&nbr_colonnes);
                                    printf("inserez les valeurs:\n");
                               for(i=0;i<nbr_lignes;i++)
                               {
                                   for(j=0;j<nbr_colonnes;j++)
                                   {
                                    printf("Mat[%d][%d]:",i,j);
                                    scanf("%d",&Mat[i][j]);
                                   }
                               }
                                if (choix_deTri==1 )// traitement matrices entiers ligne par lignes par la fonction insertion
                                {
                                       if(direct_parligne=='l')// si le choix etait matrices entiers en fonction ligne par ligne
                                  {
                                      TriMat_insertion_ligne(nbr_lignes,nbr_colonnes,Mat);
                                  }
                                 else if(direct_parligne=='d')
                                  {
                                //appelez la fonction  qui fait le traitement direct par insertion (matrices)..
                                    TriMat_insertion(nbr_lignes,nbr_colonnes,Mat);
                                  }
                                }
                                else if (choix_deTri==2)//
                                {
                                 //appelez la fct tri par selection
                                     if(direct_parligne=='l')// si le choix etait matrices entiers en fonction ligne par ligne
                                  {
                                   //   TriMAt_selectionligne(nbr_lignes,nbr_colonnes,Mat);
                                                  TriMat_selection_ligne(nbr_lignes,nbr_colonnes,Mat);
                                  }
                                 else if(direct_parligne=='d')
                               {
                                //appelez la fonction  qui fait le traitement direct par insertion (matrices)..
                                    TriMat_selection(nbr_lignes,nbr_colonnes,Mat);
                               }
                                }
                                else if (choix_deTri==3)
                                {
                                    //appelez la fonction tri par bulle
                                        if(direct_parligne=='l')// si le choix etait matrices entiers en fonction ligne par ligne

                                                TriMat_bulle_ligne(nbr_lignes,nbr_colonnes,Mat);
                                  }
                                 else if(direct_parligne=='d')
                                 {
                                     TriMat_bulle(nbr_lignes,nbr_colonnes,Mat);
                                 }

                                }
                                else if((entier_chaine=='c'|| entier_chaine=='C')) //traiter le cas des matrices chaine char
                                 {

                                                printf("OK! donnez le nbr de mot que vous voulez traiter:");
                                                scanf("%d",&nbr_de_mots);
                                                 M=malloc(nbr_de_mots*sizeof(char*));
                                                 for(i=0;i<nbr_de_mots;i++)
                                                 {
                                                    M[i]=malloc(20*sizeof(char));
                                                 }
                                                 for(i=0;i<nbr_de_mots;i++)
                                                 {
                                                    printf("sasissez le mot %d:",i+1);
                                                    scanf("%s",M[i]);
                                                 }
                                                  if(choix_deTri==1)
                                               {
                                                   TriMat_chaine_insrtion_croissant(nbr_de_mots,M);
                                               }
                                                else if (choix_deTri==2)
                                                {
                                                    TriMat_chaine_selection_croissant(nbr_de_mots,M);
                                                }
                                                else if (choix_deTri==3)
                                                {
                                                 TriMat_chaine_bulle_croissant(nbr_de_mots,M);
                                                }
                                    break;
                          case 1:
                                 if((entier_chaine=='e'|| entier_chaine=='E'))

                            {
                                   printf("mode decroissant");
                                      printf("ok donc donnez le nombre de ligne et colonnes de la matrices:\n");
                                      printf("nombre ligne:");
                                      scanf("%d",&nbr_lignes);
                                      printf("nombre de colonnes:");
                                      scanf("%d",&nbr_colonnes);
                                      printf("inserez les valeurs:\n");
                               for(i=0;i<nbr_lignes;i++)
                               {   for(j=0;j<nbr_colonnes;j++)
                                   {
                                   printf("Mat[%d][%d]:",i,j);
                                   scanf("%d",&Mat[i][j]);
                                   }
                               }

                                if (choix_deTri==1 )
                                {
                                    if(direct_parligne='l')
                                    {
                                         TriMat_insertion_decroissant(nbr_lignes,nbr_colonnes,Mat);
                                    }
                                }
                                 else if(choix_deTri==2)
                                 {
                                     TriMat_selection_decroissant(nbr_lignes,nbr_colonnes,Mat);
                                 }
                                  else if (choix_deTri==3)
                                  {
                                      TriMat_bulle_decroisant(nbr_lignes,nbr_colonnes,Mat);
                                  }
                                 }
                                 else if (entier_chaine=='c'|| entier_chaine=='C')
                                {
                                                    printf("OK! donnez le nbr de mot que vous voulez traiter:");
                                                scanf("%d",&nbr_de_mots);
                                                 M=malloc(nbr_de_mots*sizeof(char*));
                                                 for(i=0;i<nbr_de_mots;i++)
                                                 {
                                                    M[i]=malloc(20*sizeof(char));
                                                 }
                                                 for(i=0;i<nbr_de_mots;i++)
                                                 {

                                                    printf("sasissez le mot %d:",i+1);
                                                    scanf("%s",M[i]);
                                                 }
                                                  if(choix_deTri==1)
                                               {
                                                   TriMat_chaine_insrtion_decroissant(nbr_de_mots,M);
                                               }
                                                else if (choix_deTri==2)
                                                {
                                                    TriMat_chaine_selection_decroissant(nbr_de_mots,M);
                                                }
                                                else if (choix_deTri==3)
                                                {
                                                 TriMat_chaine_bulle_decroissant(nbr_de_mots,M);
                                                }
                                }
                                break; }}
                             break;
                    case 3:
                             printf("OK! vous avez choisi le traitement des listes\n");
                               printf("veuillez choisir type de tri svp(saisissez un '1' ou '2' ):\n");
                                printf("\t***1.tri de matrices par monchoix***\n");
                                printf("\t***2.tri de matrices par bulle***\n");
                                 printf("\n");

                                 do{
                                    scanf("%d",&choix_deTri);
                                     if (choix_deTri>2 || choix_deTri<1)
                                         printf("<!>Ce numero ne figure pas dans la liste!!\n ");

                                 } while((choix_deTri>2 || choix_deTri<1));

                                     if (choix_deTri==1 || choix_deTri==2)
                                     {
                                          printf("mode croissant (0) ou decroissant (1)?\n");
                                          scanf("%d",&choix_mode);
                                           if(choix_mode==0)
                                          {
                                              printf("donnez nbr d'elements:");
                                          scanf("%d",&n);
                                          une_liste=CreatList_FIFO(n);
                                          une_liste=TriListe_c(une_liste);
                                          printf("votre liste apres le tri croissant:\n");
                                          affiche_liste(une_liste);
                                        }else if (choix_mode==1)
                                          {
                                              printf("donnez nbr d'elements:");
                                          scanf("%d",&n);
                                          une_liste=CreatList_FIFO(n);
                                          une_liste=TriListe_d(une_liste);
                                          printf("votre liste apres le tri decroissant:\n");
                                          affiche_liste(une_liste);
                                          }

                                     }

                                      break;

       break; }
                                            printf("\n\n");
                                             printf("\t\t\t**************methode_supplementaire**************\n\n\n");
                                   printf("voulez vous faire une tri des TABLEAUX par une methode differente(oui:y/non:n)?\n");
                                      printf("choix:");
                                       getchar();
                                    do{
                                         scanf("%c",&choix_supp);
                                         if(choix_supp!='y'&& choix_supp!='n')
                                            printf("svp n ou y :");
                                    } while(choix_supp!='y'&& choix_supp!='n');
                                           if(choix_supp=='y')
                                           {
                                               printf("OK donc donnez nombre d'elements a trier:");
                                               scanf("%d",&nbr_elemntsTab);
                                               for(i=0;i<nbr_elemntsTab;i++)
                                               {
                                                   printf("T[%d]:",i);
                                                   scanf("%d",&T[i]);
                                               }
                                                printf("en mode croissant 0 ou decroissant 1:");
                                                scanf("%d",&choix_mode);
                                                 if(choix_mode==0)
                                                 {
                                                     printf("mode croissant\n");
                                                     Tri_supp_croissant(nbr_elemntsTab,T);
                                                     for(i=0;i<nbr_elemntsTab;i++)
                                                     {
                                                         printf("%d\t",T[i]);
                                                     }
                                                     printf("\n");
                                                 }
                                                 else if(choix_mode==1)
                                                 {
                                                      printf("mode decroissant\n");
                                                      Tri_supp_decroissant(nbr_elemntsTab,T);
                                                     for(i=0;i<nbr_elemntsTab;i++)
                                                     {
                                                         printf("%d\t",T[i]);
                                                     }
                                                        printf("\n");
                                                 }

                                           }else if (choix_supp=='n')
                                             printf("OK!\n");




  system("PAUSE");
   printf("---------------------Merci!---------------------\n");
       return 0;
       }

