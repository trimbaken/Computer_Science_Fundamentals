#include<stdio.h>
#include<stdlib.h>

#define max(x,y) x>y?x:y

typedef struct tree
{
	int include;
	int exclude;
	struct tree* left;
	struct tree* right;
} Node;

Node *root;

Node* new_node(int val)
{
	Node* temp;
	temp = (Node* )malloc(sizeof(Node ));
	temp->include = 0;
	temp->exclude =0;
	temp->left = temp->right = NULL;

	return temp;
}

void create_tree()
{
	root = new_node(10);
	root->left = new_node(20);
	root->left->left = new_node(40);
	root->left->right = new_node(50);
	root->left->right->left = new_node(70);
	root->left->right->right = new_node(80);
	root->right = new_node(30);
	root->right->right = new_node(60);
}

void get_lis(Node* tree_node)
{

	if(tree_node == NULL)
	{
		return;
	}
	if(tree_node->left == NULL && tree_node->right == NULL)
	{
		tree_node->include = 1;
		tree_node->exclude = 0;

		return;
	}
	if(tree_node->left != NULL)
	{
		get_lis(tree_node->left);
	}
	if(tree_node->right != NULL)
	{
		get_lis(tree_node->right);
	}
	tree_node->include = 1 +( ((tree_node->left !=NULL)?tree_node->left->exclude:0)
				+ ((tree_node->right !=NULL)?tree_node->right->exclude:0));

	tree_node->exclude = (tree_node->left != NULL?(max(tree_node->left->include, tree_node->left->exclude)):0)
			+ (tree_node->right != NULL?(max(tree_node->right->include, tree_node->right->exclude)):0);

	return;
}

int get_length()
{
	get_lis(root);
	return max(root->include, root->exclude);
}

int main(void)
{

	create_tree();
	printf("\n Length of largest independent set is[%d] \n", get_length());
	printf("\n Program to get length of largest independent set:\n\n");
	return 0;
}
