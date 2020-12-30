#include<stdio.h>
#include<stdlib.h>

int count_set_bits(int number)
{
	int count =0;

	while(number>0)
	{
		count += (number & 1);
		number = number >>1;
	}
	return count;
}

int extract_nibbels(int number)
{
	int mask = 0x000F;
	int i =0;
	printf("\n mask [%d]\n", mask);

	for(i =0; i<8; i++)
	{
		printf("\nNibbel %d is [%d]", i, (number & (mask<<(i*4)))>>(i*4) );
	}
	return 0;
}

void init()
{
	int number_one;
	int ret = 0;
	int operation;
	while(1)
	{
		printf("\n\nSelect operation: \n");
		printf("1 Count set bits in number: \n");
		printf("2 Extract Nibble from int: \n");
		printf("\n0 Exit: \n");

		printf("\nEnter Operation Number:\n");
		scanf("%d", &operation);
		if(operation < 0 || operation > 2)
		{
			system("clear");
			printf("\n Invalid operation selected  \n");
			continue;
		}
		system("clear");
		switch(operation)
		{
			case 1:
				{
					printf("\nCount set bits in number  \n");
					printf("Enter number \n" );
					scanf("%d", &number_one);
					ret = count_set_bits(number_one);
					if(ret == -1)
					{
						printf("\nFail to count set bits in number\n");
					}
					else
					{
						printf("\nSet bits in number [%d], are [%d]\n", number_one, ret);
					}
					break;
				}
			case 2:
				{
					printf("\nExtract Nibbels from integer:\n");
					printf("Enter integer number\n");
					scanf("%d", &number_one);
					ret = extract_nibbels(number_one);
					if(ret == -1)
					{
						printf("\nFail to extract nibbles from number [%d]\n", number_one);
					}
					break;
				}
			case 0:
				{
					printf("\n Thanks for using our service:  \n");
                                        return;
				}
			default:
                                break;
		}
	}
	return;
}

int main(void)
{
	init();
	printf("\nProgram to implement basic bitwise operations\n");
	return 0;
}
