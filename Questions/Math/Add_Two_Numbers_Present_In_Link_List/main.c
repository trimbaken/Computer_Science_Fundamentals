#include<stdio.h>
#include<stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

int stackOne[100];
int stackTwo[100];
int stackOneTop = -1;
int stackTwoTop = -1;

int isStackOneEmpty()
{
	if(stackOneTop <0)
	{
		return 1;
	}
	return 0;
}

void stackOnePush(int value)
{
	stackOneTop++;
	stackOne[stackOneTop] = value;
}

int stackOnePop()
{
	int ret =0;
	if(isStackOneEmpty())
		return 0;
	ret = stackOne[stackOneTop];
	stackOneTop--;
	return ret;
}

int isStackTwoEmpty()
{
	if(stackTwoTop <0)
	{
		return 1;
	}
	return 0;
}

void stackTwoPush(int value)
{
	stackTwoTop++;
	stackTwo[stackTwoTop] = value;
}

int stackTwoPop()
{
	int ret =0;
	if(isStackTwoEmpty())
		return 0;
	ret = stackTwo[stackTwoTop];
	stackTwoTop--;
	return ret;
}


struct ListNode* createNode(int value)
{
	struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	new_node->val = value;
	new_node->next = NULL;
	return new_node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* temp_node = NULL;
	struct ListNode* new_node = NULL;
	struct ListNode* previous_node = NULL;
	int carry =0;
	int value =0;

//	addedNumber->next = createNode(8);
//	addedNumber->next->next = createNode(0);
//	addedNumber->next->next->next = createNode(7);

	temp_node = l1;
	while(temp_node != NULL)
	{
		stackOnePush(temp_node->val);
		temp_node = temp_node->next;
	}
	temp_node = l2;
	while(temp_node != NULL)
	{
		stackTwoPush(temp_node->val);
		temp_node = temp_node->next;
	}
	value = 0;
	carry = 0;
	while(!isStackOneEmpty() || !isStackTwoEmpty())
	{
		value =0;
		value += stackOnePop();
		value += stackTwoPop();
		value += carry;
		carry = value/10;
		value %= 10;
		new_node = createNode(value);
		new_node->next = previous_node;
		previous_node = new_node;
	}
	if(carry != 0)
	{
		new_node = createNode(carry);
		new_node->next = previous_node;
	}
	return new_node;
}

int main(void)
{
	struct ListNode* l1 = createNode(7);
	l1->next = createNode(2);
	l1->next->next = createNode(4);
	l1->next->next->next = createNode(3);
	struct ListNode* l2 = createNode(5);
	l2->next = createNode(6);
	l2->next->next = createNode(4);

	struct ListNode* addedNumber = addTwoNumbers(l1, l2);

	struct ListNode* temp_node = addedNumber;
	while(temp_node != NULL)
	{
		printf("%d ", temp_node->val);
		temp_node = temp_node->next;
	}
	printf("\nProgram to add two numbers present in link list\n");
	return 0;
}
