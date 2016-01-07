#include <stdio.h>

int main(int argc, char **argv)
{
	int choix,loop=1;
	while (loop==1)
	{
		printf ("\n--------------- MENU ---------------\n");
		printf("Veuillez choisir une acton :\n");
		printf("0 - Quitter\n");
		printf("1 - Ajouter un entrainement : \n");
		printf("2 - Afficher les entrainements : \n");
		printf("3 - Modifier l entrainement d une journee : \n");
		printf("4 - Calculer la sommes des series :\n ");
		printf("5 - Calculer la moyenne des series :\n ");
		//printf("6 - affichier un histogramme des performance :\n ");
		printf("selectionnez un chiffre entre 0 et 3:");
		scanf("%d",&choix);
			if ((choix >= 0) && choix <= 9)
			{
			switch(choix)
			{
				case 0 : printf ("------Vous avez quitte le programme !! ------ \n");loop =0;break;
				case 1 : ;break;
				case 2 : break;
				case 3 : printf("Quel jour recherchez vous ? ");
				case 4 : printf("Depuis quel jour voulez vous calculez le nombre de mouvement ? ");
				case 5 : printf("+++ Fonction en cours de developement +++ \n");
				default:break;
			};
		}
		else
		{
			printf("Vous avez mal fait votre choix !!");
		}
		}
	return 0;
}

