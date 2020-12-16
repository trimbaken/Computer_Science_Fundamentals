#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 499500

typedef struct adjacency_list_node_s
{
        int adjacency_node_value;
	int weight;
        struct adjacency_list_node_s* next;
} adjacency_list_node_t;

typedef struct graph_node_s
{
        int node_value;
        struct adjacency_list_node_s* adjacency_list;
}graph_node_t;

graph_node_t graph_node[MAX_NODES];
adjacency_list_node_t adjacency_list_node[MAX_EDGES];

int graph_node_count = -1;
int adjacency_list_node_count = -1;

adjacency_list_node_t* create_adjacency_list_node(int adjacency_node_value, int weight)
{
	if(adjacency_list_node_count >= MAX_EDGES)
		return NULL;
	adjacency_list_node_count++;
	adjacency_list_node[adjacency_list_node_count].adjacency_node_value = adjacency_node_value;
	adjacency_list_node[adjacency_list_node_count].weight = weight;
	adjacency_list_node[adjacency_list_node_count].next = NULL;

	return &adjacency_list_node[adjacency_list_node_count];
}

graph_node_t* create_graph_node(int graph_node_value)
{
	if(graph_node_count >= MAX_NODES)
		return NULL;
	graph_node_count++;
	graph_node[graph_node_count].node_value = graph_node_value;
	graph_node[graph_node_count].adjacency_list = NULL;

	return &graph_node[graph_node_count];
}

int insert_edge(int start_node, int end_node, int weight)
{
//	printf("\n Insert Edge start_node : %d, end_node : %d, weight : %d \n", start_node, end_node, weight);

	if(graph_node[start_node].node_value == -1 || graph_node[start_node].adjacency_list == NULL)
	{
		graph_node[start_node].node_value = start_node;
		graph_node[start_node].adjacency_list = create_adjacency_list_node(end_node, weight);
	}
	else
	{
		adjacency_list_node_t *list_node = graph_node[start_node].adjacency_list;
		while(list_node->next != NULL || list_node->adjacency_node_value != end_node)
		{
			if(list_node->adjacency_node_value == end_node)
			{
				printf("Edge present ");
				return 0;
			}

			list_node = list_node->next;
		}
		if(list_node->adjacency_node_value == end_node)
		{
			printf("Edge present ");
			return 0;
		}
		list_node->next = create_adjacency_list_node(end_node, weight);
	}
	return 1;
}

int serach_node(int node_index)
{
	if(graph_node[node_index].node_value != -1)
	{
		return 1;
	}
	return 0;
}

int delete_node(int node_index)
{
	if(!serach_node(node_index))
	{
		printf("\n Node [%d] is not present  \n", node_index);
		return 0;
	}
	else
	{
		graph_node[node_index].node_value = -1;
		graph_node[node_index].adjacency_list = NULL;
	}
	return 1;
}

int search_edge(int start_node, int end_node, int weight)
{
	adjacency_list_node_t* list_node;
	if(!serach_node(start_node))
	{
		printf("\nNode not present \n");
		return 0;
	}
	list_node = graph_node[start_node].adjacency_list;
	while(list_node != NULL)
	{
		if(list_node->adjacency_node_value == end_node && list_node->weight == weight)
		{
			return 1;
		}
		list_node = list_node->next;
	}
	return 0;
}

int delete_edge(int start_node, int end_node, int weight)
{
	adjacency_list_node_t* list_node;
	if(!serach_node(start_node))
	{
		printf("\nNode not present \n");
		return 0;
	}
	list_node = graph_node[start_node].adjacency_list;
	// Delete first edge
	if(list_node->adjacency_node_value == end_node && list_node->weight == weight)
	{
		graph_node[start_node].adjacency_list = list_node->next;
		return 1;
	}
	adjacency_list_node_t* previous_node = list_node;
	list_node = list_node->next;
	while(list_node != NULL)
	{
		if(list_node->adjacency_node_value == end_node && list_node->weight == weight)
		{
			previous_node->next = list_node->next;
			return 1;
		}
		previous_node = list_node;
		list_node = list_node->next;
	}
	return 0;
}

int modify_edge(int start_node, int end_node, int weight, int new_weight)
{
	adjacency_list_node_t* list_node;
	if(!serach_node(start_node))
	{
		printf("\nNode not present \n");
		return 0;
	}
	list_node = graph_node[start_node].adjacency_list;
	while(list_node != NULL)
	{
		if(list_node->adjacency_node_value == end_node && list_node->weight == weight)
		{
			list_node->weight = new_weight;
			return 1;
		}
		list_node = list_node->next;
	}
	return 0;
}


void init()
{
	int operation =0;
	int start_node =0;
	int end_node =0;
	int weight =0;
	int new_weight =0;
	int node_index =0;

	int i =0;
	for(i =0; i<MAX_NODES; i++)
	{
		graph_node[i].node_value = -1;
	}
	for(i=0; i<MAX_EDGES; i++)
	{
		adjacency_list_node[i].adjacency_node_value = -1;
	}
	while(1)
	{
		printf("\n\nSelect operation: \n");
		printf("1 Insert Edge: \n");
		printf("2 Search Node: \n");
		printf("3 Delete Node: \n");
		printf("4 Search Edge: \n");
		printf("5 Delete Edge: \n");
		printf("6 Modify Edge: \n");
		printf("7 Print All Element: \n");
		printf("\n0 Exit: \n");

		printf("\nEnter Operation Number:\n");
		scanf("%d", &operation);
		if(operation < 0 || operation > 7)
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
					if(!insert_edge(start_node, end_node, weight))
					{
						printf("\nFail to create edge\n");
					}
					else
					{
						printf("\nEdge is created\n");
					}
					break;
				}
			case 2:
				{
					printf("\n Search Node  \n");
					printf("Enter Node Index\n" );
					scanf("%d", &node_index);
					if(!serach_node(node_index))
					{
						printf("\n Node [%d] is not present  \n", node_index);
					}
					else
					{
						printf("\n Node [%d] is present \n", node_index);
					}
					break;
				}
			case 3:
				{
					printf("\n Delete Node  \n");
					printf("\n Enter Node Index  \n");
					scanf("%d", &node_index);
					if(!delete_node(node_index))
					{
						printf("\nFail to delete node [%d]  \n", node_index);
					}
					else
					{
						printf("\nDeleted node [%d]\n", node_index);
					}

					break;
				}

			case 4:
				{
					printf("\n Search Edge  \n");
					printf("Enter Start Node, End Node, Weight of Edge \n" );
					scanf("%d %d %d", &start_node, &end_node, &weight);
					if(!search_edge(start_node, end_node, weight))
					{
						printf("\n Edge [%d][%d][%d] is not present  \n", start_node, end_node, weight);
					}
					else
					{
						printf("\n Edge [%d][%d][%d] is present  \n", start_node, end_node, weight);
					}
					break;
				}
			case 5:
				{
					printf("\n Delete Edge  \n");
					printf("Enter Start Node, End Node, Weight of Edge \n" );
					scanf("%d %d %d", &start_node, &end_node, &weight);
					if(!delete_edge(start_node, end_node, weight))
					{
						printf("\nFail to delete edge [%d][%d][%d]  \n", start_node, end_node, weight);
					}
					else
					{
						printf("\nDeleted edge [%d][%d][%d]  \n", start_node, end_node, weight);
					}

					break;
				}
			case 6:
				{
					printf("\n Modify Edge \n");
					printf("Enter Start Node, End Node, Weight of Edge, New Weight \n" );
					scanf("%d %d %d %d", &start_node, &end_node, &weight, &new_weight);
					if(!modify_edge(start_node, end_node, weight, new_weight))
					{
						printf("\nFail to modify edge [%d][%d][%d]  \n", start_node, end_node, weight);
					}
					else
					{
						printf("\nModified edge [%d][%d][%d]  \n", start_node, end_node, weight);
					}


					break;
				}
			case 7:
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
