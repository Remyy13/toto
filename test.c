#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAILLE 20
#define BACK_RED  "\x1B[41m"
#define BACK_GREEN "\x1B[42m"
#define RESET "\033[0m"
#include <unistd.h>

 
// Selection d'un nombre au hasard entre Min et Max.
 
int ReturnRandomNumber (int Min, int Max)
{
    int Result;
    Result = ((rand() % (int)(((Max) + 1) - (Min))) + (Min));
    return Result;
}
 
 
 
// Initialisation au hasard du damier

void Initialisation(int damier[][TAILLE],int taille)
{
     int i,j;
// cellule vivante = 1
// cellule morte = 0
     
    srand(time(NULL));
     
    for ( i=0; i<taille; i++)
        for ( j=0; j<taille; j++)
            damier[i][j] = ReturnRandomNumber(0,1);
     
}


// Affichage du damier (O pour les cellules vivants, et - pour les mortes)
 
void Affichage(int tableau[][TAILLE], int taille)
{
int i,j;

        for ( i=0; i<TAILLE; i++)
        {
                for (j=0; j<TAILLE; j++)
                {
                        tableau[i][j]?printf(BACK_GREEN"  "RESET" "):printf(BACK_RED"  "RESET" ");
                }
        printf("\n\n");
        }

}
 
 
 
 
// Calcul du nombre de voisins (vivants)
 
int NombreDeVoisins(int damier[][TAILLE],int ligne, int colonne)
{
    int voisinsVivants = 0,i,j;
    int ligneEnCour, colonneEnCour;
    int cellule = damier[ligne][colonne];
      
    for ( i=(ligne-1);i<=(ligne+1); i++)               
    {
        for ( j=(colonne-1); j<=(colonne+1); j++)
        {
            ligneEnCour = (i+TAILLE)%TAILLE;          // On revient sur les bords opposés (Matrice 'torique')
            colonneEnCour = (j+TAILLE)%TAILLE;
                 
            if (damier[ligneEnCour][colonneEnCour] == 1)
                voisinsVivants++;
        }
    }
 
    voisinsVivants = voisinsVivants - cellule;          // Si la Cellule elle même est vivante on ne la compte pas
    return(voisinsVivants);
}
 
 
 
 
// Génération suivante
 
void NextGeneration(int damier[][TAILLE])
{
    int damierTampon[TAILLE][TAILLE];
     int i,j,voisins,cellule;
    for ( i=0; i<TAILLE; i++)
    {
        for ( j=0; j<TAILLE; j++)
        {
             voisins = NombreDeVoisins(damier,i,j);
             cellule = damier[i][j];
            if ((voisins < 2)||(voisins > 3))
            {
                    damierTampon[i][j] = 0;
            }
     
            else if(voisins == 3)
            {
                
                    damierTampon[i][j] = 1;
            }
            else if (voisins == 2)
                {
                        damierTampon[i][j]=damier[i][j];
                }
        }
    }
    for ( i=0; i<TAILLE; i++)
        for ( j=0; j<TAILLE; j++)
            damier[i][j] = damierTampon[i][j];
}

void automate(int Cycle ,int damier[][TAILLE], int taille)
{
	int i;
	    for (i=0; i<Cycle; i++)
    {
        NextGeneration(damier);
        system("clear");
        Affichage(damier,TAILLE);
        usleep(100000);
        printf("\n\n");
    }
	}
int main()
{
    int damier[TAILLE][TAILLE];
    int Cycle;
    int loop=1, choix;
        
    	while (loop==1)
	{
		printf ("\n--------------- MENU ---------------\n");
		printf("Veuillez choisir une acton :\n");
		printf("1 - Quitter le programme : \n");
		printf("2 - Choix du nombre de cycle  \n");
		printf("3 - Initialiser le jeu:\n");
		printf("4 - Lancer le jeu :\n");
		printf("5 - Allocation dynamique (in progress");
		printf("selectionnez un chiffre entre 0 et 8:\n");
		scanf("%d",&choix);
			if ((choix >= 1) && choix <= 9)
			{
			switch(choix)
			{
				case 1 : printf ("------Vous allez quitter le programme. A bientot!! ------ \n");loop =0; usleep(2000000);break;
				case 2 : printf("Choisissez le nombre de cycle :");scanf("%d",&Cycle);break;
				case 3 : Initialisation(damier, TAILLE);break;
				case 4 : automate(Cycle, damier, TAILLE);break;
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
		 system("clear");
		}
}
