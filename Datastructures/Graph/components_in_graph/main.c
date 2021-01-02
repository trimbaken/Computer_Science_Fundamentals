#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

int N;
int src;
int dest;
int max_size = 0;
int min_size = INT_MAX;

typedef struct queue_node
{
	int val;
	struct queue_node* next;
}Node;

typedef struct comm_member
{
        int element;
        struct comm_member* next;
} member;

typedef struct input_struct
{
        bool visited;
        member *list;
        member *last_element;
}input_t;

input_t input[30001];
Node* front = NULL;
Node* rear = NULL;

Node* create_queue_node(int val)
{
	Node* temp = (Node* )malloc(sizeof(Node* ));
	temp->val = val;
	temp->next = NULL;

	return temp;
}

void enqueue(int val)
{
	Node* temp = create_queue_node(val);
	if(front == NULL)
	{
		front = temp;
	}
	else
	{
		rear->next = temp;
	}
	rear = temp;
}

bool is_empty()
{
	if(front == NULL)
		return 1;

	return 0;
}

int dequeue()
{
	int ret = 0;
	if(!is_empty())
	{
		ret = front->val;
		front = front->next;
	}

	return ret;
}

member* create_member(int element)
{
        member* temp = (member*)malloc(sizeof(member*));
        temp->element = element;
        temp->next = NULL;

        return temp;
}

void init()
{
        int i =0;
        for(i =0; i<=2*N; i++)
        {
                input[i].visited = 0;
                input[i].list = NULL;
                input[i].last_element = NULL;
        }
	front = NULL;
	rear = NULL;
	max_size = 0;
	min_size = INT_MAX;
        return ;
}

void create_edge(int source, int destination)
{
	member* temp;
	temp = create_member(destination);
	if(input[source].list == NULL)
	{
		input[source].list = temp;
	}
	else
	{
		input[source].last_element->next = temp;
	}
		input[source].last_element = temp;
}
void add_egde()
{
	printf("\n src[%d] dest[%d]", src, dest);

	create_edge(src, dest);
	create_edge(dest, src);
	return ;
}

void print_edges()
{
	int i =0;
	member* temp = NULL;
	for(i=0; i<=2*N; i++)
	{
		if(input[i].list != NULL)
		{
			temp = input[i].list;
			printf("\n Src[%d] \t",i);
			while(temp != NULL)
			{
				printf("[%d]\t",temp->element);
				temp = temp->next;
			}
		}
	}

	return ;
}

void get_component_size(int start)
{
	int component_size = 0;
	int current;

	member* temp;

	input[start].visited = true;
	enqueue(start);

	while(!is_empty())
	{
		current = dequeue();
		component_size++;
		if(input[current].list != NULL)
		{
			temp = input[current].list;
			while(temp != NULL)
			{
				if(input[temp->element].visited == false)
				{
					input[temp->element].visited = true;
					enqueue(temp->element);
				}
				temp = temp->next;
			}
		}
	}
	if(component_size > max_size)
	{
		max_size = component_size;
	}
	if(component_size>1 && component_size < min_size)
	{
		min_size = component_size;
	}

	return ;
}
void get_size()
{
	int i;

	for(i =0; i<=2*N; i++)
	{
		if(input[i].visited == false)
		{
			get_component_size(i);
		}
	}

	return ;
}

int main(void)
{
	system("clear");
	int i;

	scanf("%d",&N);
	init();
	for(i=0; i<N; i++)
	{
		scanf("%d %d",&src,&dest);
		add_egde();
	}
//	print_edges();
	get_size();
	printf("%d %d\n",min_size, max_size);
	printf("\nProgram to find max and min size of connected components\n");

	return 0;
}
