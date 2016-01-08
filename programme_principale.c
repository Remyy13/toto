#include <stdio.h>

int main(int argc, char **argv)
{
	int choix,loop=1;
	while (loop==1)
	{
		printf("toto1")
		printf ("\n--------------- MENU ---------------\n");
		printf("Veuillez choisir une acton :\n");
		printf("1 - Quitter le programme : \n");
		printf("2 -  Sauvegarder l'automate dans un fichier': \n");
		printf("3 -  Charger l'automate depuis un fichier: \n");
		printf("4 -  Creer et/ou modifier les cellule de l'automate'\n");
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
				case 2 : break;
				case 3 : printf("Quel jour recherchez vous ? ");break;
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

