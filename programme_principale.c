#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"
#define TAILLE_MATRICE 20
//void Init_matrice(int matrice[][TAILLE_MATRICE],int TAILLE_MATRICE);
//int RandomNumber(int,int);


 
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
                printf(COLOR_GREEN "1  " COLOR_RESET);
            else printf(COLOR_RED "#  " COLOR_RESET);
        }
         
        printf("\n");
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
				case 4 : printf("Depuis quel jour voulez vous calculez le nombre de mouvement ? ");break;
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

