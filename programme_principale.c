#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define COLOR_RED     "\x1b[41m"
#define COLOR_GREEN   "\x1b[42m"
#define COLOR_RESET   "\x1b[0m"
#define TAILLE_MATRICE 5
#define TAILLE_MATRICE_INT 4
//void Init_matrice(int matrice[][TAILLE_MATRICE],int TAILLE_MATRICE);
//int RandomNumber(int,int);



/*void allocation_matrice()
{
	int Longueur,Largeur;
	int i;
	int** mat=NULL;
	printf("Longueur :");
	scanf("%d",&Longueur);
	printf("Largeur :");
	scanf("%d",&Largeur);
	mat = malloc(sizeof(int)*Longueur);
	    for (i = 0; i < Longueur; i++) 
	    {
        mat[i] = malloc(sizeof(char) * Largeur); // Allocation de la deuxième dimension pour chaque nom : prenoms[i][100]
        mat[i]=5;
		}
		for (i = 0; i < Longueur; i++)
        printf("\nprénom %d : %d ", i, mat[i]);
	}


*/



 
// Selection d'un nombre au hasard entre Min et Max.
 
int ReturnRandomNumber (int Min, int Max)
{
    int Result;
    Result = ((rand() % (int)(((Max) + 1) - (Min))) + (Min));
    return Result;
}
 
 
 
// Initialisation au hasard du damier
 
void init_tab(int fenetre[][TAILLE_MATRICE],int taille)
{
     
// cellule vivante = 1
// cellule morte = 0
     
    srand(time(NULL));
     
    for (int i=0; i<taille; i++)
    {
        for (int j=0; j<taille; j++)
        {
            fenetre[i][j] = ReturnRandomNumber(0,1);
		}
     }
}

 
void Affichage_matrice(int tableau[][TAILLE_MATRICE], int taille)
{
    for (int i=0; i<TAILLE_MATRICE; i++)
    {
        for (int j=0; j<TAILLE_MATRICE; j++)
        {
            if (tableau[i][j] == 0)
                printf(COLOR_GREEN "  " COLOR_RESET" ");
            else printf(COLOR_RED "  " COLOR_RESET" ");
        }
         
        printf("\n\n");
    }
}


/* Calcul du nombre de voisins vivants */
int nombre_voisins (int fenetre[][TAILLE_MATRICE], int ligne, int colonne)
{
   int compte=0; // compteur de cellules
   int i,j;
   for (i=ligne-1;i<=ligne+1;i++)
      for(j=colonne-1;j<=colonne+1;j++)
         compte=compte+fenetre[i][j];

         /* Puis on retire celle du milieu */
         compte -= fenetre[ligne][colonne];
         return compte;
	 }

void mise_a_jour(int fenetre[ ][TAILLE_MATRICE ])
{
   int i,j;
   int nbr_voisins;
   int fenetre_densite[TAILLE_MATRICE_INT][TAILLE_MATRICE];
   // matrice qui comptabilise le nombre de voisins case par case
   for(i=0; i< TAILLE_MATRICE_INT; i++)
         for(j=0; j< TAILLE_MATRICE_INT; j++)
            fenetre_densite[i][j]=nombre_voisins(fenetre,i+1,j+1);
      // i+1 et j+1 car on passe de la MATRICE_INT à la MATRICE

   for(i=0; i< TAILLE_MATRICE_INT; i++)
      for(j=0; j< TAILLE_MATRICE_INT; j++)
      {
            nbr_voisins=fenetre_densite[i][j];
            if(nbr_voisins==2)
                  fenetre[i+1][j+1]=1;
            else if (nbr_voisins==0 || nbr_voisins==4)
                  fenetre[i+1][j+1]=0;
		}
}

int main(int argc, char **argv)
{
	int choix,loop=1;
    int fenetre[TAILLE_MATRICE][TAILLE_MATRICE];
    

	while (loop==1)
	{
		printf("toto");
		printf ("\n--------------- MENU ---------------\n");
		printf("Veuillez choisir une acton :\n");
		printf("1 - Quitter le programme : \n");
		printf("2 -  Initialiser le jeu': \n");
		printf("3 -  Affichier l'automate initial' \n");
		printf("4 -  Creer et/ou mo,difier les cellule de l'automate'\n");
		printf("5 - Parametrer le recadrage de l'affichage (x0, h, y0, v) :\n");
		printf("6 - calculer l'automate jusqu'a un temps (t) donne sans affichage:\n");
		printf("7 - Afficher l'automate au temps (t) courant\n");
		printf("8 - Calculer et afficher entre t0 et t1 (0 < t0 < t1)\n");
		printf("selectionnez un chiffre entre 0 et 8:\n");
		scanf("%d",&choix);
			if ((choix >= 1) && choix <= 9)
			{
			switch(choix)
			{
				case 1 : printf ("------Vous avez quitte le programme !! ------ \n");loop =0;break;
				case 2 : init_tab(fenetre, TAILLE_MATRICE);;break;
				case 3 : Affichage_matrice(fenetre,TAILLE_MATRICE);break;
				case 4 : allocation_matrice();break;
				case 5 : printf("+++ Fonction en cours de developement +++ \n");break;
				case 6 : break;
				case 7 : break;
				case 8 : break;
				default:break;
			};
		}
		else
		{
			printf("\n##################################\nVous avez mal fait votre choix !!\n##################################\n");
		}
		}
	return 0;
}

