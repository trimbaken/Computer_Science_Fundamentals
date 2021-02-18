#include<stdio.h>

int romanToInt(char * s){
	int ret =0;
	int i =0;

	while(s[i] != '\0')
	{
		printf("%c ", s[i]);
		if(s[i] == 'M')
		{
			ret += 1000;
		}
		else if(s[i] == 'D')
		{
			ret += 500;
		}
		else if(s[i] == 'C')
		{
			if(s[i+1] != '\0' && s[i+1] == 'M')
			{
				ret += 900;
				i++;
			}
			else if(s[i+1] != '\0' && s[i+1] == 'D')
			{
				ret += 400;
				i++;
			}
			else
			{
				ret += 100;
			}
		}
		else if(s[i] == 'L')
		{
			ret += 50;
		}
		else if(s[i] == 'X')
		{
			if(s[i+1] != '\0' && s[i+1] == 'C')
			{
				ret += 90;
				i++;
			}
			else if(s[i+1] != '\0' && s[i+1] == 'L')
			{
				ret += 40;
				i++;
			}
			else
			{
				ret += 10;
			}
		}
		else if(s[i] == 'V')
		{
			ret += 5;
		}
		else if(s[i] == 'I')
		{
			if(s[i+1] != '\0' && s[i+1] == 'X')
			{
				ret += 9;
				i++;
			}
			else if(s[i+1] != '\0' && s[i+1] == 'V')
			{
				ret += 4;
				i++;
			}
			else
			{
				ret += 1;
			}
		}
		i++;
	}

	return ret;
}

int main(void)
{
	char input[4000];
	printf("\nEnter Roman Number\n");
	scanf("%s", input);
	printf("\n Integer Number is : %d\n", romanToInt(input));
	printf("\nProgram to convert Roman number to Integer number\n");
	return 0;
}
