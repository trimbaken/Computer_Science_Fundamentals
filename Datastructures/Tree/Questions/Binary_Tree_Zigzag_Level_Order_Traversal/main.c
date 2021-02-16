#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} ;

struct TreeNode TreeNodeArray[100];
int TreeNodeArrayCount =-1;

struct TreeNode* root = NULL;

struct TreeNode* GetTreeNode(int val)
{
	TreeNodeArrayCount++;
	TreeNodeArray[TreeNodeArrayCount].val = val;
	TreeNodeArray[TreeNodeArrayCount].left = NULL;
	TreeNodeArray[TreeNodeArrayCount].right = NULL;

	return &TreeNodeArray[TreeNodeArrayCount];
}

void insert_element(int value)
{
	struct TreeNode* new_node = NULL;
	struct TreeNode* temp_node = NULL;
	if(root == NULL)
	{
		printf("\n First element  \n");
		root = GetTreeNode(value);
	}
	else
	{
		temp_node = root;
		while(temp_node != NULL)
		{
			if(temp_node->val == value)
			{
				printf("\n Element %d is already present in tree  \n", value);
				return;
			}
			else if(value < temp_node->val)
			{
				if(temp_node->left == NULL)
				{
					new_node = GetTreeNode(value);
					temp_node->left = new_node;
					break;
				}
				else
				{
					temp_node = temp_node->left;
				}
			}
			else
			{
				if(temp_node->right == NULL)
				{
					new_node = GetTreeNode(value);
					temp_node->right = new_node;
					break;
				}
				else
				{
					temp_node = temp_node->right;
				}
			}
		}
	}
	printf("\n inserted %d \n", value);
}

struct TreeNode* StackOne[100];
int StackOneTop = -1;

struct TreeNode* StackTwo[100];
int StackTwoTop = -1;

void StackOnePush(struct TreeNode* node)
{
	StackOneTop++;
	StackOne[StackOneTop] = node;
}

struct TreeNode* StackOnePop()
{
	if(StackOneTop ==-1)
	{
		return NULL;
	}
	struct TreeNode* ret = NULL;
	ret = StackOne[StackOneTop];
	StackOneTop--;
	return ret;
}

void StackTwoPush(struct TreeNode* node)
{
	StackTwoTop++;
	StackTwo[StackTwoTop] = node;
}

struct TreeNode* StackTwoPop()
{
	if(StackTwoTop ==-1)
	{
		return NULL;
	}
	struct TreeNode* ret = NULL;
	ret = StackTwo[StackTwoTop];
	StackTwoTop--;
	return ret;
}



int** zigzagLevelOrder(struct TreeNode* root_node, int* returnSize, int** returnColumnSizes)
{
	*returnSize = 0;

        if (root == NULL)
        {
                return NULL;
        }

	int** arr = (int**)malloc(sizeof(int*)*10000);
        *returnColumnSizes = (int*)malloc(sizeof(int)*10000);
	int arrIndex = 0;
	int i =0;

	struct TreeNode* temp_node = root_node;
	struct TreeNode* current_node = NULL;
/*	StackOnePush(temp_node);
	current_node = StackOnePop();
	printf("\n current_node %d\n", current_node->val);
	StackTwoPush(temp_node);
	current_node = StackTwoPop();
	printf("\n current_node %d\n", current_node->val);
*/
	StackTwoPush(temp_node);

	while(StackOneTop != -1 || StackTwoTop != -1)
	{
		printf("\n");
		if(StackTwoTop != -1)
		{
			arr[arrIndex] = (int*)malloc((StackTwoTop + 1)*sizeof(int));
                        (*returnColumnSizes)[arrIndex] = StackTwoTop+1;
		}
		i =0;
		while(StackTwoTop != -1)
		{
			current_node = StackTwoPop();
			printf("[%d] ", current_node->val);
			arr[arrIndex][i] = current_node->val;
			i++;

			if(current_node->left != NULL)
			{
				StackOnePush(current_node->left);
			}
			if(current_node->right != NULL)
			{
				StackOnePush(current_node->right);
			}
		}
		printf("\n");
		if(StackOneTop != -1)
		{
			arr[arrIndex] = (int*)malloc((StackOneTop+1)*sizeof(int));
                        (*returnColumnSizes)[arrIndex] = StackOneTop+1;
		}
		i =0;
		while(StackOneTop != -1)
		{
			current_node = StackOnePop();
			printf("[%d] ", current_node->val);
			arr[arrIndex][i] = current_node->val;
			if(current_node->right != NULL)
			{
				StackTwoPush(current_node->right);
			}
			if(current_node->left != NULL)
			{
				StackTwoPush(current_node->left);
			}
		}
		arrIndex++;
                (*returnSize)++;
	}
	return arr;

}

int main(void)
{

	insert_element(10);
	insert_element(5);
	insert_element(7);
	insert_element(20);
	insert_element(15);
	insert_element(17);
	insert_element(25);
	insert_element(30);
	printf("\n root node %d\n", root->val);
	printf("\n root left node %d\n", root->left->val);
	printf("\n root right node %d\n", root->right->val);
	printf("\n root left node %d\n", root->right->left->val);
	printf("\n root right node %d\n", root->right->right->val);

//	PrintZigzag(root);

	printf("\nProgram to implement binary tree zigzag level order traversal\n");
	return 0;
}

/*
 * struct TreeNode* StackOne[1000];
int StackOneTop = -1;

struct TreeNode* StackTwo[1000];
int StackTwoTop = -1;

void StackOnePush(struct TreeNode* node)
{
	StackOneTop++;
	StackOne[StackOneTop] = node;
}

struct TreeNode* StackOnePop()
{
	if(StackOneTop ==-1)
	{
		return NULL;
	}
	struct TreeNode* ret = NULL;
	ret = StackOne[StackOneTop];
	StackOneTop--;
	return ret;
}

void StackTwoPush(struct TreeNode* node)
{
	StackTwoTop++;
	StackTwo[StackTwoTop] = node;
}

struct TreeNode* StackTwoPop()
{
	if(StackTwoTop ==-1)
	{
		return NULL;
	}
	struct TreeNode* ret = NULL;
	ret = StackTwo[StackTwoTop];
	StackTwoTop--;
	return ret;
}



int** zigzagLevelOrder(struct TreeNode* root_node, int* returnSize, int** returnColumnSizes)
{
	*returnSize = 0;

        if (root_node == NULL)
        {
                return NULL;
        }

	int** arr = (int**)malloc(sizeof(int*)*10000);
    *returnColumnSizes = (int*)malloc(sizeof(int)*10000);
	int arrIndex = 0;
	int i =0;

	struct TreeNode* temp_node = root_node;
	struct TreeNode* current_node = NULL;
*	StackOnePush(temp_node);
	current_node = StackOnePop();
	printf("\n current_node %d\n", current_node->val);
	StackTwoPush(temp_node);
	current_node = StackTwoPop();
	printf("\n current_node %d\n", current_node->val);
*
	StackTwoPush(temp_node);

	while(StackOneTop != -1 || StackTwoTop != -1)
	{
		printf("\n");
		if(StackTwoTop != -1)
		{
			arr[arrIndex] = (int*)malloc((StackTwoTop + 1)*sizeof(int));
            (*returnColumnSizes)[arrIndex] = StackTwoTop+1;
		}
		i =0;
		while(StackTwoTop != -1)
		{
			current_node = StackTwoPop();
			printf("[%d] ", current_node->val);
			arr[arrIndex][i] = current_node->val;
			i++;

			if(current_node->left != NULL)
			{
				StackOnePush(current_node->left);
			}
			if(current_node->right != NULL)
			{
				StackOnePush(current_node->right);
			}
		}
		printf("\n");
        arrIndex++;
        (*returnSize)++;

		if(StackOneTop != -1)
		{
			arr[arrIndex] = (int*)malloc((StackOneTop+1)*sizeof(int));
            (*returnColumnSizes)[arrIndex] = StackOneTop+1;
            (*returnSize)++;
		}
		i =0;
		while(StackOneTop != -1)
		{
			current_node = StackOnePop();
			printf("[%d] ", current_node->val);
			arr[arrIndex][i] = current_node->val;
            i++;
			if(current_node->right != NULL)
			{
				StackTwoPush(current_node->right);
			}
			if(current_node->left != NULL)
			{
				StackTwoPush(current_node->left);
			}
		}
        if(StackOneTop != -1 || StackTwoTop != -1)
        {
		    arrIndex++;

        }
	}

	return arr;

}

 * */
