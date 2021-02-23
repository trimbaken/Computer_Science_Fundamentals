#include<stdio.h>


//  Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};



struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	struct ListNode* ret = head;
	struct ListNode* temp_array[32];
	struct ListNode* temp_node = NULL;
	int count =0;
	int i =0;
	temp_node = head;

	for(i=0; i<32; i++)
	{
		temp_array[i] = NULL;
	}
	while(temp_node != NULL)
	{
		count++;
		temp_array[count] = temp_node;
		temp_node = temp_node->next;
	}
	temp_node = temp_array[count-n];
	if(temp_node != NULL)
	{
		temp_node->next = temp_array[count-n+2];
	}
	if(count-n ==0)
	{
		ret = temp_array[2];
	}
	else
	{
		ret = temp_array[1];
	}
	return ret;
}

int main(void)
{
	struct ListNode node[30];
	struct ListNode* temp_node = NULL;
	node[0].val = 1;
	node[0].next = &node[1];
	node[1].val = 2;
	node[1].next = &node[2];
	node[2].val = 3;
	node[2].next = &node[3];
	node[3].val = 4;
	node[3].next = &node[4];
	node[4].val = 5;
	node[4].next = NULL;

	temp_node = removeNthFromEnd(&node[0], 5);
	while(temp_node != NULL)
	{
		printf("%d ", temp_node->val);
		temp_node = temp_node->next;
	}
	printf("\n Program to remove kth node from end of list\n");
	return 0;
}
