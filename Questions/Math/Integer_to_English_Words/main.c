#include<stdio.h>
#define B 1000000000
#define M 1000000
#define T 1000
#define H 100

char output[100];
int output_index =0;
typedef struct one_to_nine_s
{
	char word[10];
}one_to_nine_t;
one_to_nine_t one_to_nine[11];
one_to_nine_t ten_to_ninety[11];
one_to_nine_t elevel_to_ninetine[20];
int is_initialize =0;

void my_strcpy(char* dest, char* src, int dest_index)
{
	int i =0;
	while(src[i] != '\0')
	{
		dest[dest_index] = src[i];
		dest_index++;
		i++;
	}
	dest[dest_index] = '\0';

	printf("\n %s", dest);
}

void copy_to_output(char* src)
{
	int i =0;
	while(src[i] != '\0')
	{
		output[output_index] = src[i];
		output_index++;
		i++;
	}
	output[output_index] = ' ';
	output_index++;
}


void init()
{
	my_strcpy(one_to_nine[1].word, "One",0);
	my_strcpy(one_to_nine[2].word, "Two",0);
	my_strcpy(one_to_nine[3].word, "Three",0);
	my_strcpy(one_to_nine[4].word, "Four",0);
	my_strcpy(one_to_nine[5].word, "Five",0);
	my_strcpy(one_to_nine[6].word, "Six",0);
	my_strcpy(one_to_nine[7].word, "Seven",0);
	my_strcpy(one_to_nine[8].word, "Eight",0);
	my_strcpy(one_to_nine[9].word, "Nine",0);
	my_strcpy(one_to_nine[10].word, "Ten",0);

	my_strcpy(ten_to_ninety[1].word, "Ten",0);
	my_strcpy(ten_to_ninety[2].word, "Twenty",0);
	my_strcpy(ten_to_ninety[3].word, "Thirty",0);
	my_strcpy(ten_to_ninety[4].word, "Forty",0);
	my_strcpy(ten_to_ninety[5].word, "Fifty",0);
	my_strcpy(ten_to_ninety[6].word, "Sixty",0);
	my_strcpy(ten_to_ninety[7].word, "Seventy",0);
	my_strcpy(ten_to_ninety[8].word, "Eighty",0);
	my_strcpy(ten_to_ninety[9].word, "Ninety",0);

	my_strcpy(elevel_to_ninetine[11].word, "Eleven", 0);
	my_strcpy(elevel_to_ninetine[12].word, "Twelve", 0);
	my_strcpy(elevel_to_ninetine[13].word, "Thirteen", 0);
	my_strcpy(elevel_to_ninetine[14].word, "Fourteen", 0);
	my_strcpy(elevel_to_ninetine[15].word, "Fifteen", 0);
	my_strcpy(elevel_to_ninetine[16].word, "Sixteen", 0);
	my_strcpy(elevel_to_ninetine[17].word, "Seventeen", 0);
	my_strcpy(elevel_to_ninetine[18].word, "Eighteen", 0);
	my_strcpy(elevel_to_ninetine[19].word, "Nineteen", 0);

	output_index =0;
}

void numberToWords_(int num)
{
	int temp_num =0;
	if(num>= H)
	{
		temp_num = num/H;
		copy_to_output(one_to_nine[temp_num].word);
		copy_to_output("Hundred");
		num = num%H;
	}
	if(num>=20)
	{
		temp_num = num/10;
		copy_to_output(ten_to_ninety[temp_num].word);
		num = num%10;
	}
	if(num>10)
	{
		copy_to_output(elevel_to_ninetine[num].word);
		num =0;
	}
	if(num>=1)
	{
		copy_to_output(one_to_nine[num].word);
	}
}

char * numberToWords(int num){
	int temp_num =0;
//	output[0] = 'a';
//	output[1] = '\0';
	if(num == 0)
	{
		copy_to_output("Zero");
	}
	if(is_initialize == 0)
        {
            init();
            is_initialize =1;
        }
	printf("\n num %d\n", num);

	if(num >= B)
	{
		temp_num = num/B;
		num = num%B;
		numberToWords_(temp_num);
		copy_to_output("Billion");
		printf("\n %d Billion ", temp_num);
	}
	if(num >= M)
	{
		temp_num = num/M;
		num = num%M;
		numberToWords_(temp_num);
		copy_to_output("Million");
		printf("\n %d Million", temp_num);
	}
	if(num >= T)
	{
		temp_num = num/T;
		num = num%T;
		numberToWords_(temp_num);
		copy_to_output("Thousand");
		printf("\n %d Thousand", temp_num);
	}
	/*
	if(num >= H)
	{
		temp_num = num/H;
		num = num%H;
		numberToWords_(temp_num);
		printf("\n %d Hundred", temp_num);
	}
	*/
	if(num > 0)
	{
		numberToWords_(num);
	}
	output[output_index-1] = '\0';
	return output;
}

int main(void)
{
	int num = 12345;
	printf("\n Integer %d, word %s\n", num, numberToWords(num));
	printf("\nInteger to English Words\n");
	return 0;
}
