#include<stdio.h>
#include<stdlib.h>

void init()
{
	int operation =0;
	while(1)
	{
		printf("\n Select operation \n");
		printf("1 Insert Element: \n");
		printf("2 Search Element: \n");
		printf("3 Delete Element: \n");
		printf("4 Modify Element: \n");
		printf("5 Smallest Element: \n");
		printf("6 Largest Element: \n");
		printf("\n0 Exit: \n");

		printf("\n Enter Operation Number:\n");
		scanf("%d", &operation);
		if(operation < 0 || operation > 6)
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
				printf("\n Insert Element  \n");
				break;
			}
			case 2:
			{
				printf("\n Search Element  \n");
				break;
			}
			case 3:
			{
				printf("\n Delete Element  \n");
				break;
			}
			case 4:
			{
				printf("\n Modify Element  \n");
				break;
			}
			case 5:
			{
				printf("\n Smallest Element  \n");
				break;
			}
			case 6:
			{
				printf("\n Largest Element  \n");
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
}

int main(void)
{
	system("clear");

	init();

	printf("\n Program to implement Binary Search Tree and its operations.  \n\n");
	return 0;
}
