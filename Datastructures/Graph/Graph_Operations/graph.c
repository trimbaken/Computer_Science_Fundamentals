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

typedef struct stack_s
{
	int stack_node_value;
}stack_t;

typedef struct queue_s
{
	int queue_node_value;
	struct queue_s* next;
	struct queue_s* prev;
}queue_t;

graph_node_t graph_node[MAX_NODES];
adjacency_list_node_t adjacency_list_node[MAX_EDGES];
stack_t stack_dfs[MAX_EDGES];
queue_t queue_bfs[MAX_EDGES];

int graph_node_count = 0;
int adjacency_list_node_count = -1;
int stack_dfs_top =0;
int queue_bfs_count =0;
queue_t* queue_bfs_front = NULL;
queue_t* queue_bfs_end = NULL;


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

int insert_edge(int start_node, int end_node, int weight)
{
	printf("\n Insert Edge start_node : %d, end_node : %d, weight : %d", start_node, end_node, weight);

	if(graph_node[start_node].node_value == -1 || graph_node[start_node].adjacency_list == NULL)
	{
		graph_node[start_node].node_value = start_node;
		graph_node[start_node].adjacency_list = create_adjacency_list_node(end_node, weight);
		graph_node_count++;
	}
	else
	{
		adjacency_list_node_t *list_node = graph_node[start_node].adjacency_list;
		while(list_node->next != NULL)
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
		graph_node_count--;
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

void print_graph_nodes()
{
	int number_of_nodes = 0;
	int i =0;
	printf("\nAll graph nodes :\n");
	for(i =0; (i<MAX_NODES) && (number_of_nodes < graph_node_count); i++)
	{
		if(graph_node[i].node_value != -1)
		{
			number_of_nodes++;
			printf(" Node : %d \n", graph_node[i].node_value);
		}
	}
}

void insert_bi_directional_edge(int start_node, int end_node, int weight)
{
	if(!insert_edge(start_node, end_node, weight))
	{
		printf("\nFail to insert edge\n");
	}
	if(!insert_edge(end_node, start_node, weight))
	{
		printf("\nFail to insert edge\n");
	}
}

void create_graph()
{
	insert_bi_directional_edge(0, 1, 4);
	insert_bi_directional_edge(0, 7, 8);
	insert_bi_directional_edge(1, 2, 8);
	insert_bi_directional_edge(1, 7, 11);
	insert_bi_directional_edge(2, 3, 7);
	insert_bi_directional_edge(2, 8, 2);
	insert_bi_directional_edge(2, 5, 4);
	insert_bi_directional_edge(3, 4, 9);
	insert_bi_directional_edge(3, 5, 14);
	insert_bi_directional_edge(5, 6, 2);
	insert_bi_directional_edge(6, 8, 6);
	insert_bi_directional_edge(6, 7, 1);
	insert_bi_directional_edge(7, 8, 7);
}

int is_stack_dfs_empty()
{
	if(stack_dfs_top == -1)
		return 1;
	return 0;
}

int stack_dfs_push(int graph_node)
{
	printf("\n DFS Traverser Node [%d]", graph_node);
	stack_dfs_top++;
	stack_dfs[stack_dfs_top].stack_node_value = graph_node;
	return 1;
}

int stack_dfs_pop()
{
	int ret =-1;
	if(is_stack_dfs_empty())
	{
		printf("\nDFS Stack is Empty \n");
		return ret;
	}
	ret = stack_dfs[stack_dfs_top].stack_node_value;
	stack_dfs_top--;
	return ret;
}

int get_stack_dfs_top_node()
{
	if(is_stack_dfs_empty())
	{
		printf("\nDFS Stack is Empty \n");
		return -1;
	}
	return (stack_dfs[stack_dfs_top].stack_node_value);

}

int dfs(int start_node)
{
	int visited[MAX_NODES];
	int i =0;
	int pop_current_node =0;
	int current_node =0;
	adjacency_list_node_t* list_node = NULL;
	stack_dfs_top = -1;
	if(!serach_node(start_node))
	{
		printf("\n Node not present  \n");
		return 0;
	}
	for(i =0; i<MAX_NODES; i++)
	{
		visited[i] = 0;
	}
	if(stack_dfs_push(start_node) == -1)
	{
		printf("\n Fail to push into stack\n");
		return 0;
	}
	visited[start_node] =1;
	while(!is_stack_dfs_empty())
	{
		current_node = get_stack_dfs_top_node();
		pop_current_node = 1;
		list_node = graph_node[current_node].adjacency_list;
		while(list_node != NULL)
		{
			if(visited[list_node->adjacency_node_value] == 0)
			{
				if(stack_dfs_push(list_node->adjacency_node_value) == -1)
				{
					printf("\nFail to push into stack\n");
					return 0;
				}
				pop_current_node = 0;
				visited[list_node->adjacency_node_value] =1;
				break;
			}
			list_node = list_node->next;
		}
		if(pop_current_node)
		{
			if(stack_dfs_pop() == -1)
			{
				printf("\nFail to pop from stack\n");
				return 0;
			}
		}
	}
	return 1;
}

int is_queue_bfs_empty()
{
	if(queue_bfs_front == NULL)
	{
		printf("\nBFS Queue is empty\n");
		return 1;
	}
	return 0;
}

queue_t* create_queue_bfs_node(int value)
{
	queue_bfs[queue_bfs_count].queue_node_value = value;
	queue_bfs[queue_bfs_count].next = NULL;
	queue_bfs[queue_bfs_count].prev = NULL;

	return &queue_bfs[queue_bfs_count++];
}

int queue_bfs_push(int value)
{
	if(queue_bfs_count >= MAX_NODES)
	{
		printf("\nQueue size is full\n");
		return 0;
	}
	if(queue_bfs_front == NULL)
	{
		queue_bfs_front = queue_bfs_end = create_queue_bfs_node(value);
	}
	else
	{
		queue_bfs_end->next = create_queue_bfs_node(value);
		queue_bfs_end = queue_bfs_end->next;
	}
	printf("\n BFS Traverser Node [%d]", value);
	return 1;
}

int queue_bfs_pop()
{
	int queue_element;
	if(is_queue_bfs_empty())
	{
		return -1;
	}
	queue_element = queue_bfs_front->queue_node_value;
	if(queue_bfs_front == queue_bfs_end)
	{
		queue_bfs_front = queue_bfs_end = NULL;
		return queue_element;
	}
	queue_bfs_front = queue_bfs_front->next;
	return queue_element;
}

int get_queue_bfs_front_element()
{
	if(is_queue_bfs_empty())
	{
		return -1;
	}
	return queue_bfs_front->queue_node_value;
}

int bfs(int start_node)
{
	int visited[MAX_NODES];
	int i =0;
	int pop_current_node =0;
	int current_node =0;
	queue_bfs_count = 0;
	queue_bfs_front = NULL;
	queue_bfs_end = NULL;
	adjacency_list_node_t* list_node = NULL;
	if(!serach_node(start_node))
	{
		printf("\n Node not present  \n");
		return 0;
	}
	for(i =0; i<MAX_NODES; i++)
	{
		visited[i] = 0;
	}
	if(queue_bfs_push(start_node) == 0)
	{
		printf("\n Fail to push into queue\n");
		return 0;
	}
	visited[start_node] =1;
	while(!is_queue_bfs_empty())
	{
		current_node = queue_bfs_pop();
		list_node = graph_node[current_node].adjacency_list;
		while(list_node != NULL)
		{
			if(visited[list_node->adjacency_node_value] == 0)
			{
				if(queue_bfs_push(list_node->adjacency_node_value) == 0)
				{
					printf("\nFail to push into queue\n");
					return 0;
				}
				visited[list_node->adjacency_node_value] =1;
			}
			list_node = list_node->next;
		}
	}
	return 1;
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
		printf("7 Print All Nodes: \n");
		printf("8 Create Graph: \n");
		printf("9 Graph Traversal - DFS: \n");
		printf("10 Graph Traversal - BFS: \n");
		printf("\n0 Exit: \n");

		printf("\nEnter Operation Number:\n");
		scanf("%d", &operation);
		if(operation < 0 || operation > 10)
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
					print_graph_nodes();
					break;
				}
			case 8:
				{
					printf("\n Create Graph  \n");
					create_graph();
					break;
				}
			case 9:
				{
					printf("\n Graph Traversal - DFS  \n");
					printf("Enter start node :\n");
					scanf("%d", &start_node);
					if( !dfs(start_node))
					{
						printf("\nGraph traversal using DFS failed\n");
					}
					break;
				}
			case 10:
				{
					printf("\n Graph Traversal - BFS  \n");
					printf("Enter start node :\n");
					scanf("%d", &start_node);
					if(!bfs(start_node))
					{
						printf("\nGraph traversal using BFS failed\n");
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
}


int main(void)
{
	printf("\n Program to execute all graph operations:\n");
	init();
	return false;
}
