/***************************************
            JEU DE LA VIE
***************************************/
#include <stdio.h> 
#include <stdlib.h> 
#define TAILLE_SOUS_MATRICE 7
/* On peut avoir 7 * 7 cellules vivantes */
#define TAILLE_SUR_MATRICE  9
/* On place une bordure autour qui facilite la vie du programmeur... */
/***************** PROTOTYPES ***********************/
void init(int matrice [][TAILLE_SUR_MATRICE ]);
int nombre_voisins (int matrice [][TAILLE_SUR_MATRICE ],
                    int ligne, int colonne);
void mise_a_jour(int matrice[][TAILLE_SUR_MATRICE ]);
void affiche_matrice(int matrice [][TAILLE_SUR_MATRICE ]);
void ligne(int largeur);
/*****************************************************/
int main( ) {
   int i;
   int nbr_cycles;
   int matrice[TAILLE_SUR_MATRICE] [TAILLE_SUR_MATRICE ];
   
   printf("Nombre de cycles : ");
   scanf("%i",&nbr_cycles);
   init(matrice);
   printf("La population au départ : \n");
   affiche_matrice(matrice);
   printf("Pressez sur ENTER pour continuer...\n");
   for(i=0; i<nbr_cycles; i++) {
      mise_a_jour (matrice);
      printf("La population après %d cycles: \n", i+1);
      affiche_matrice (matrice);
      printf("Pressez sur ENTER pour continuer...\n");
   }
   return 0;
}

/****************************************/
/* Initialisation de la matrice */
void init(int matrice [][TAILLE_SUR_MATRICE ]) {
/****************************************/
   int i,j;
   for(i=0; i<7 ; i++)
    {
      for(j=0; j<7 ; j++) 
      {
         if (i<=j && i>0 && j<=7)
            matrice[i][j]=1;
         else
            matrice[i][j]=0; 
      }
   }
   /* On pourrait aussi faire une initialisation aléatoire */
}
/****************************************/
/* Calcul du nombre de voisins vivants */
int nombre_voisins (int matrice[][TAILLE_SUR_MATRICE ],
                    int ligne, int colonne) {
/****************************************/
   int compte=0; /* compteur de cellules */
   int i,j;
/* On additionne les 9 cellules centrées en ligne,colonne */
   for (i=ligne-1;i<=ligne+1;i++)
      for(j=colonne-1;j<=colonne+1;j++)
         compte=compte+matrice[i][j];
 
         /* Puis on retire celle du milieu... */
         compte -= matrice[ligne][colonne];
         return compte;
}

/****************************************/
/* Correspond à l'étape n+1 */
void mise_a_jour(int matrice[ ][TAILLE_SUR_MATRICE ]) {
/****************************************/
   int i,j;
   int nbr_voisins;
   int matrice_densite[TAILLE_SOUS_MATRICE][TAILLE_SOUS_MATRICE];
   /* matrice qui comptabilise le nombre de voisins */
   /* et cela, case par case */
   for(i=0; i< TAILLE_SOUS_MATRICE; i++)
         for(j=0; j< TAILLE_SOUS_MATRICE; j++)
            matrice_densite[i][j]=nombre_voisins(matrice,i+1,j+1);
      /* i+1 et j+1 car on passe de la SOUS_MATRICE à la MATRICE   */
   
   for(i=0; i< TAILLE_SOUS_MATRICE; i++)
      for(j=0; j< TAILLE_SOUS_MATRICE; j++) {
            nbr_voisins=matrice_densite[i][j];
            if(nbr_voisins==2)
                  matrice[i+1][j+1]=1;
            else if (nbr_voisins==0 || nbr_voisins==4)
                  matrice[i+1][j+1]=0;
   }
}

/****************************************/
/* Affichage à l'écran des cellules vivantes */
void affiche_matrice(int matrice[ ][TAILLE_SUR_MATRICE ]) {
/****************************************/
   int i,j;
   for(i=1; i<=TAILLE_SOUS_MATRICE; i++) {
      ligne(7);
      for(j=1; j<= TAILLE_SOUS_MATRICE; j++)
         if (matrice[i][j]==1)
            printf("|%c",'*');
         else
            printf("|%c",'|');
      printf("|\n");
   }
   ligne(TAILLE_SOUS_MATRICE);
}
/****************************************/
/* Tracé d'une ligne */
void ligne(int largeur) {
/****************************************/
   int i;
   for(i=0; i<largeur; i++)
      printf("+-");
   printf("+\n");
}
