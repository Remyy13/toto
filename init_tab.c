#include <stdio.h>
void init_tab(int tableau[][120]);
int main(int argc, char **argv)
{
	int tableau[120][120];
	init_tab(tableau);
	return 0;
}
void init_tab(int tableau[][120])
{
	int i = 0,j = 0;
	for (i=0; i<120; i++)
	{
		for(j = 0 ; j < 120 ; j++)
		{
		 if (i<=j && i>0 && j<=120)
            tableau[i][j]=1;
         else
            tableau[i][j]=0; 
			printf("%d",tableau[i][j]);
		}
		printf("\n");
	}
}
