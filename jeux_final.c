#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAILLE 20
#define BACK_RED  "\x1B[41m"
#define BACK_GREEN "\x1B[42m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#include <unistd.h>
int ReturnRandomNumber (int Min, int Max);
void Initialisation(int damier[][TAILLE],int taille);
int NombreDeVoisins(int damier[][TAILLE],int ligne, int colonne);
void NextGeneration(int damier[][TAILLE]);
void automate(int Cycle ,int damier[][TAILLE], int taille);
void Save_automate(FILE* file_automate, int damier[][TAILLE], int taille);
 
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
     
    for ( i=0; i < taille; i++)
    {
        for ( j=0; j < taille; j++)
        {
            damier[i][j] = ReturnRandomNumber(0,1);
		}
	}
     
}


// Affichage du damier (O pour les cellules vivants, et - pour les mortes)
 
void Affichage(int tableau[][TAILLE], int taille)
{
int i,j;

        for ( i=0; i<TAILLE; i++)
        {
                for (j=0; j<TAILLE; j++)
                {
                        tableau[i][j] ? printf(BACK_GREEN"  "RESET" ") : printf(BACK_RED"  "RESET" ");
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
      
    for ( i = (ligne - 1) ; i <= (ligne+1); i++)               
    {
        for ( j=(colonne - 1) ; j<=(colonne + 1); j++)
        {
            ligneEnCour = (i + TAILLE) % TAILLE;          // On revient sur les bords opposés (Matrice 'torique')
            colonneEnCour = (j + TAILLE) % TAILLE;
                 
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
     int i,j,voisins;
    for ( i=0; i < TAILLE; i++)
    {
        for ( j=0; j < TAILLE; j++)
        {
             voisins = NombreDeVoisins(damier, i, j);
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
        for ( j=0; j < TAILLE; j++)
            damier[i][j] = damierTampon[i][j];
}

void automate(int Cycle, int damier[][TAILLE], int taille)
{
	int i;
	for (i=0; i < Cycle+1; i++)
    {

        NextGeneration(damier);
        system("clear");
        printf (BOLD"Cycle : %d\n"RESET,i );
        Affichage(damier,TAILLE);
        usleep(400000);
    }
	}


void Save_automate(FILE* file_automate, int damier[][TAILLE], int taille)
{
	int i = 0 ,j = 0;
	file_automate = fopen("automate.txt", "a+");
	if((file_automate == NULL))
	{
    printf("Impossible d'ouvrir le fichier'.\n");
	}
	else
	{
	    for ( i=0; i<TAILLE; i++)
		{
			fwrite(damier[TAILLE],sizeof(int),taille,file_automate);
			for ( j=0; j<TAILLE; j++)
			{
				fprintf (file_automate, "%d", damier[i][j]);; 
				
			}
			fprintf (file_automate,"\n");
		}
	fclose(file_automate);
	}
}

/*void Read_automate(FILE* file_automate, int damier[][TAILLE], int taille)
{
	int i = 0 ,j = 0;
	file_automate = fopen("automate.txt", "r");
	if((file_automate == NULL))
	{
    printf("Impossible d'ouvrir le fichier'.\n");
	}
	else
	{
	    for ( i=0; i<TAILLE; i++)
		{
			fwrite(damier[TAILLE],sizeof(int),taille,file_automate);
			for ( j=0; j<TAILLE; j++)
			{
				fscanf(file_automate, "%d", damier[i][j]);; 
				
			}
			fprintf (file_automate,"\n");
		}
	fclose(file_automate);
	}
}*/
int main(int argc, char *argv[])
{
	FILE* file_automate = NULL;
    int damier[TAILLE][TAILLE];
    int Cycle;
    int loop=1, choix;
        system("clear");
    	while (loop==1)
	{
		printf ("\n##################################\n#              MENU              #\n##################################\nn");
		printf("Veuillez choisir une acton :\n");
		printf("1 - Quitter le programme : \n");
		printf("2 - Choix du nombre de cycle  \n");
		printf("3 - Initialiser le jeu:\n");
		printf("4 - Lancer le jeu :\n");
		printf("5 - Allocation dynamique (in progress)\n");
		printf("6 - Afficher la derniere iteration : \n");
		printf("7 - Sauvegarder l'automate : \n");
		printf("8 - Charger l'automate : (in progress)\n");
		printf("selectionnez un chiffre entre 0 et 8:\n");
		scanf("%d",&choix);
			if ((choix >= 1) && choix <= 8)
			{
				switch(choix)
				{
				case 1 : printf ("------Vous allez quitter le programme. A bientot!! ------ \n");loop =0; usleep(2000000);break;
				case 2 : printf("Choisissez le nombre de cycle :");scanf("%d",&Cycle);break;
				case 3 : Initialisation(damier, TAILLE);break;
				case 4 : automate(Cycle, damier, TAILLE);break;
				case 5 : printf("+++ Fonction en cours de developement +++ \n");break;
				case 6 : Affichage(damier,TAILLE);usleep(5000000);break;
				case 7 : Save_automate(file_automate, damier, TAILLE);break;
				case 8 : //Read_automate(file_automate, damier, TAILLE);break;
				default:break;
				};
			}
			else
			{
				printf("\n##################################\nVous avez mal fait votre choix !!\n##################################\n") ;usleep(2000000);
			}
		 system(" clear ") ;
		}
	}
