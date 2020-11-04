#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#include"graph.h"

void init()
{
	int operation =0;
	int start_node =0;
	int end_node =0;
	int weight =0;
	int new_weight =0;
	int node_index =0;
	while(1)
	{
		printf("\n Select operation \n");
		printf("1 Insert Edge: \n");
		printf("2 Search Node: \n");
		printf("3 Delete Node: \n");
		printf("4 Delete Edge: \n");
		printf("5 Modify Edge: \n");
		printf("6 Print All Element: \n");
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
					printf("\n Insert Edge  \n");
					printf("Enter Start Node, End Node, Weight of Edge \n" );
					scanf("%d %d %d", &start_node, &end_node, &weight);
					break;
				}
			case 2:
				{
					printf("\n Search Node  \n");
					printf("Enter Node Index\n" );
					scanf("%d", &node_index);
					break;
				}
			case 3:
				{
					printf("\n Delete Node  \n");
					printf("\n Enter Node Index  \n");
					scanf("%d", &node_index);
					break;
				}
			case 4:
				{
					printf("\n Delete Edge  \n");
					printf("Enter Start Node, End Node, Weight of Edge \n" );
					scanf("%d %d %d", &start_node, &end_node, &weight);
					break;
				}
			case 5:
				{
					printf("\n Modify Edge \n");
					printf("Enter Start Node, End Node, Weight of Edge, New Weight \n" );
					scanf("%d %d %d %d", &start_node, &end_node, &weight, &new_weight);
					break;
				}
			case 6:
				{
					printf("\n Print All Graph Nodes  \n");
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
	printf("\n Program to execute all graph operations:\n");
	init();
	return false;
}
