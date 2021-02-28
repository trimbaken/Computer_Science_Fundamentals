#include<stdio.h>
#define MAX_NODE 10000
#define MAX_VAL 20002

struct Node {
	int val;
	struct Node *next;
	struct Node *random;
};

struct Node input[MAX_NODE];
struct Node output[MAX_NODE];
int output_count =-1;

struct Node_{
	struct Node* input_node;
	struct Node* output_node;
	struct Node_* next;
};

struct Node_ node_[MAX_NODE];
int node_count =-1;
struct Node_* visited[MAX_VAL];

struct Node_* get_node(struct Node* input_node_ptr, struct Node* output_node_ptr)
{
	node_count++;
	node_[node_count].input_node = input_node_ptr;
	node_[node_count].output_node = output_node_ptr;
	node_[node_count].next = NULL;

	return &node_[node_count];
}

struct Node* create_output_node(int val)
{
	output_count++;
	output[output_count].val = val;
	output[output_count].next = NULL;
	output[output_count].random = NULL;

	return &output[output_count];
}

struct Node* copyRandomList(struct Node* head)
{
	struct Node* ret = NULL;
	struct Node* temp_node = NULL;
	struct Node* previous_node = NULL;
	struct Node* output_node = NULL;
	struct Node* output_random_node = NULL;
	struct Node* temp_random_node = NULL;
	struct Node_* temp_node_ = NULL;
	struct Node_* temp_random_node_ = NULL;
	int i =0;
	int is_visited =0;

	output_count = -1;
	node_count = -1;

	if(head == NULL)
	{
		return NULL;
	}
	for(i=0; i<MAX_VAL; i++)
	{
		visited[i] = NULL;
	}
	temp_node = head;
	while(temp_node != NULL)
	{
		output_random_node = NULL;
		output_node = NULL;
		if(visited[temp_node->val + MAX_NODE] == NULL)
		{
			output_node = create_output_node(temp_node->val);
			visited[temp_node->val + MAX_NODE] = get_node(temp_node, output_node);
		}
		else
		{
			temp_node_ = visited[temp_node->val + MAX_NODE];
			is_visited =0;
			while(temp_node_ != NULL)
			{
				if(temp_node_->input_node == temp_node)
				{
					output_node = temp_node_->output_node;
					is_visited =1;
					break;
				}
				temp_node_ = temp_node_->next;
			}
			if(is_visited == 0)
			{
				output_node = create_output_node(temp_node->val);
				temp_node_ = visited[temp_node->val+ MAX_NODE];
				while(temp_node_->next != NULL)
				{
					temp_node_ = temp_node_->next;
				}
				temp_node_->next = get_node(temp_node, output_node);
			}
		}
		if(temp_node->random == NULL)
		{
			output_node->random = NULL;
		}
		else
		{
			temp_random_node = temp_node->random;
			if(visited[temp_random_node->val + MAX_NODE] == NULL)
			{
				output_random_node = create_output_node(temp_random_node->val);
				visited[temp_random_node->val + MAX_NODE] = get_node(temp_random_node, output_random_node);
			}
			else
			{
				temp_random_node_ = visited[temp_random_node->val + MAX_NODE];
				is_visited =0;
				while(temp_random_node_ != NULL)
				{
					if(temp_random_node_->input_node == temp_random_node)
					{
						output_random_node = temp_random_node_->output_node;
						is_visited =1;
						break;
					}
					temp_random_node_ = temp_random_node_->next;
				}
				if(is_visited == 0)
				{
					output_random_node = create_output_node(temp_random_node->val);
					temp_random_node_ = visited[temp_random_node->val+ MAX_NODE];
					while(temp_random_node_->next != NULL)
					{
						temp_random_node_ = temp_random_node_->next;
					}
					temp_random_node_->next = get_node(temp_random_node, output_random_node);
				}
			}
		}
		output_node->random = output_random_node;
		if(previous_node != NULL)
		{
			previous_node->next = output_node;
		}
		previous_node = output_node;
		temp_node = temp_node->next;
	}
	return &output[0];
}

int main(void)
{
	struct Node* temp_node = NULL;
	input[0].val = 7;
	input[0].next = &input[1];
	input[0].random = NULL;
	input[1].val = 13;
	input[1].next = &input[2];
	input[1].random = &input[0];
	input[2].val = 11;
	input[2].next = &input[3];
	input[2].random = &input[4];
	input[3].val = 10;
	input[3].next = &input[4];
	input[3].random = &input[2];
	input[4].val = 1;
	input[4].next = NULL;
	input[4].random = &input[0];

	temp_node = copyRandomList(&input[0]);

	while(temp_node != NULL)
	{
		printf("\n Node val [%d]\n", temp_node->val);
		if(temp_node->random != NULL)
		{
			printf("\n Random Node val [%d]\n", temp_node->random->val);
		}
		temp_node =temp_node->next;
	}

	printf("\nProgram to copy link list with random pointer\n");
	return 0;
}
