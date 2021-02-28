#include<stdio.h>

char output[100];

char * intToRoman(int num){
	int i =0;
	int temp =0;
	int output_count =0;
	if(num >= 1000)
	{
		temp = num/1000;
		for(i =0; i<temp; i++)
		{
			output[output_count] = 'M';
			output_count++;
		}
		num %= 1000;
	}
	if(num >= 900)
	{
		temp = num/900;
		for(i=0; i<temp; i++)
		{
			output[output_count] = 'C';
			output_count++;
			output[output_count] = 'M';
			output_count++;
		}
		num %= 900;
	}
	if(num >= 500)
	{
		output[output_count] = 'D';
		output_count++;
		num %= 500;
	}
	if(num >= 400)
	{
		output[output_count] = 'C';
		output_count++;
		output[output_count] = 'D';
		output_count++;
		num %= 400;
	}
	if(num >=100)
	{
		temp = num/100;
		for(i=0; i<temp; i++)
		{
			output[output_count]= 'C';
			output_count++;
		}
		num %=100;
	}
	if(num >= 90)
	{
		temp = num/90;
		for(i=0; i<temp; i++)
		{
			output[output_count] = 'X';
			output_count++;
			output[output_count] = 'C';
			output_count++;
		}
		num %= 90;
	}
	if(num >= 50)
	{
		output[output_count] = 'L';
		output_count++;
		num %= 50;
	}
	if(num >= 40)
	{
		output[output_count] = 'X';
		output_count++;
		output[output_count] = 'L';
		output_count++;
		num %= 40;
	}
	if(num >=10)
	{
		temp = num/10;
		for(i=0; i<temp; i++)
		{
			output[output_count]= 'X';
			output_count++;
		}
		num %=10;
	}
	if(num >= 9)
	{
		temp = num/9;
		for(i=0; i<temp; i++)
		{
			output[output_count] = 'I';
			output_count++;
			output[output_count] = 'X';
			output_count++;
		}
		num %= 9;
	}
	if(num >= 5)
	{
		output[output_count] = 'V';
		output_count++;
		num %= 5;
	}
	if(num >= 4)
	{
		output[output_count] = 'I';
		output_count++;
		output[output_count] = 'V';
		output_count++;
		num %= 4;
	}
	if(num >=1)
	{
		temp = num/1;
//		printf("\nTemp %d\n", temp);
		for(i=0; i<temp; i++)
		{
			output[output_count]= 'I';
			output_count++;
		}
		num %=1;
	}
	output[output_count] = '\0';
	return &output[0];
}

int main(void)
{
	int num = 4;
	char* roman = intToRoman(num);

	printf("\nInteger [%d], Roman [%s]\n", num, roman);
	printf("\nProgram to convert Integer to Roman\n");
	return 0;
}
