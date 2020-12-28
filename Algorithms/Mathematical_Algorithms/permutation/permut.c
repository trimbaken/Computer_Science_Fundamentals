#include<stdio.h>

void swap(char* str1, char* str2)
{
	char temp;
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void permut(char *str, int l, int r)
{
	int i =0;
	if(l == r)
	{
		printf("\n %s", str);
		return;
	}
	else
	{
		for(i = l; i<r; i++)
		{
			swap((str+l), (str+i));
			permut(str, l+1, r);
			swap((str+l), (str+i));
		}
	}
}

int main(void)
{
	char str[10] = "ABC";
	permut(str, 0, 3);
	printf("\n programt to get permutation's a string: \n");
	return 0;
}
