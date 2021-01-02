#include<stdio.h>
#include<stdlib.h>

char sym[100];
char op[100];
int sym_size;
int op_size;
int T[100][100];
int F[100][100];

int get_number()
{
	int i =0;
	int j =0;
	int k =0;
	int tik =0;
	int tkj =0;
	int size =0;

	for(i=0; i<sym_size; i++)
	{
		if(sym[i] == 'T')
		{
			T[i][i] = 1;
			F[i][i] = 0;
		}
		if(sym[i] == 'F')
		{
			T[i][i] = 0;
			F[i][i] = 1;
		}
	}
	for(size = 2; size<= sym_size; size++)
	{
		for(i =0; i<=(sym_size- size); i++)
		{
			j = i+size-1;
			for(k =i; k<j; k++)
			{
				tik = T[i][k] + F[i][k];
				tkj = T[k+1][j] + F[k+1][j];
				if(op[k] == '|')
				{
					F[i][j] += F[i][k]*F[k+1][j];
					T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]);
				}
				if(op[k] == '^')
				{
					T[i][j] += T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j];
					F[i][j] += T[i][k]*T[k+1][j] + F[i][j]*F[k+1][j];
				}
				if(op[k] == '&')
				{
					T[i][j] += T[i][k]*T[k+1][j];
					F[i][j] += (tik*tkj) - T[i][k]*T[k+1][j];
				}
			}
		}
	}

	return T[0][sym_size-1];
}

int main(void)
{
	system("clear");
	int i =0;

	scanf("%d",&sym_size);
	scanf("%d",&op_size);
	scanf("%s",sym);
	scanf("%s",op);
	printf("\n Number of way to parenthesize expression to ture is:[%d]\n", get_number());
	printf("\n parenthesize the expression so that the value of expression evaluates to true.\n\n");
	return 0;
}
