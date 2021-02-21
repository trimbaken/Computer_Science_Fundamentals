#include<stdio.h>
#include<stdlib.h>


//Definition for a Node.
struct Node {
	int val;
	int numNeighbors;
	struct Node** neighbors;
};

struct Node input_graph[101];
struct Node output_graph[101];

void copy_node(struct Node *s)
{
	struct Node* temp_node =NULL;
	int i =0;
	output_graph[s->val].val = s->val;
	output_graph[s->val].numNeighbors = s->numNeighbors;
	output_graph[s->val].neighbors = (struct Node**)malloc(s->numNeighbors*sizeof(struct Node*));
	for(i =0; i<s->numNeighbors; i++)
        {
                temp_node = s->neighbors[i];
//                printf(" Neighbors %d", temp_node->val);
		output_graph[s->val].neighbors[i] = &output_graph[temp_node->val];
        }
	return;
}

void print_output_graph()
{
	int i =0;
	int j =0;
	struct Node* temp_node =NULL;
	struct Node* s =NULL;

	for(i=0; i<101; i++)
	{
		if(output_graph[i].val == i)
		{
			s = &output_graph[i];
			printf("\n\n val [%d] numNeighbors [%d]\n", s->val, s->numNeighbors);

			printf(" All Neighbors:\n");
			for(j =0; j<s->numNeighbors; j++)
			{
				temp_node = s->neighbors[j];
				printf(" Neighbors %d", temp_node->val);
			}

		}
	}
	return ;
}
struct Node *cloneGraph(struct Node *s) {
	struct Node* ret = NULL;
	struct Node* temp_node = NULL;
	struct Node* temp_neighbor_node = NULL;
	struct Node* stack[101];
	int stack_index =-1;
	int i =0;

	if(s == NULL)
		return NULL;

	for(i=0; i<101; i++)
	{
		output_graph[i].val = -1;
	}
	stack_index++;
	stack[stack_index] = s;

	while(stack_index >=0)
	{
		temp_node = stack[stack_index];
		stack_index--;
		copy_node(temp_node);
		for(i =0; i<temp_node->numNeighbors; i++)
		{
			temp_neighbor_node = temp_node->neighbors[i];
			if(output_graph[temp_neighbor_node->val].val == -1)
			{
				stack_index++;
				stack[stack_index] = temp_neighbor_node;
				copy_node(temp_neighbor_node);
			}
		}
	}
/*
	printf("\n val [%d] numNeighbors [%d]\n", s->val, s->numNeighbors);

	printf("\n All Neighbors:\n");
	for(i =0; i<s->numNeighbors; i++)
	{
		temp_node = s->neighbors[i];
		printf(" Neighbors %d", temp_node->val);
	}
*/
	ret = &output_graph[s->val];
	return ret;
}

int main(void)
{
	struct Node* temp_node = NULL;
	input_graph[1].val = 1;
	input_graph[1].numNeighbors = 2;
	input_graph[2].val = 2;
	input_graph[2].numNeighbors = 2;
	input_graph[3].val = 3;
	input_graph[3].numNeighbors = 2;
	input_graph[4].val = 4;
	input_graph[4].numNeighbors = 2;

	input_graph[1].neighbors = (struct Node**)malloc(input_graph[1].numNeighbors*sizeof(struct Node*));
	input_graph[1].neighbors[0] = &input_graph[2];
	input_graph[1].neighbors[1] = &input_graph[4];
	input_graph[2].neighbors = (struct Node**)malloc(input_graph[2].numNeighbors*sizeof(struct Node*));
	input_graph[2].neighbors[0] = &input_graph[1];
	input_graph[2].neighbors[1] = &input_graph[3];
	input_graph[3].neighbors = (struct Node**)malloc(input_graph[3].numNeighbors*sizeof(struct Node*));
	input_graph[3].neighbors[0] = &input_graph[2];
	input_graph[3].neighbors[1] = &input_graph[4];
	input_graph[4].neighbors = (struct Node**)malloc(input_graph[4].numNeighbors*sizeof(struct Node*));
	input_graph[4].neighbors[0] = &input_graph[1];
	input_graph[4].neighbors[1] = &input_graph[3];

	temp_node = input_graph[1].neighbors[1];
	printf("\n Neighbors of 1 is %d\n", temp_node->val);

	temp_node = cloneGraph(&input_graph[1]);
	printf("\nStart Node of output graph %d\n", temp_node->val);
	print_output_graph();
//	cloneGraph(&input_graph[2]);
//	cloneGraph(&input_graph[3]);
//	cloneGraph(&input_graph[4]);

	printf("\nProgram to Clone input graph\n");
	return 0;
}
