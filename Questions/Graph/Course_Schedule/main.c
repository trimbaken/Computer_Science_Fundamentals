#include<stdio.h>
#include<stdbool.h>

#define MAX_COURSE 100002
#define MAX_PREREQUISITES 5002

typedef struct parent_s
{
	int val;
	struct parent_s* next;
}parent_t;

typedef struct node_s
{
	int val;
	parent_t* parent_list;
}node_t;

bool canFinish(int numCourses, int prerequisites[MAX_PREREQUISITES][2], int prerequisitesSize, int* prerequisitesColSize){
	int i =0;
	int j =0;
	int a =0;
	int b =0;
	bool ret =1;
	node_t node[MAX_COURSE];
	parent_t parent[MAX_PREREQUISITES];
	int node_count = -1;
	int parent_count =-1;
	int bfs[MAX_COURSE];
	int bfs_start =0;
	int bfs_end =0;
	int visited[MAX_COURSE];
	int visit_count = 0;
	parent_t* temp_parent;
	int current_node;
	if(prerequisitesSize == 0)
	{
		return 1;
	}
	printf("\n numCourses %d, prerequisitesColSize %d, prerequisitesColSize %d\n", numCourses, prerequisitesSize, *prerequisitesColSize);

	for(i =0; i< prerequisitesSize; i++)
	{
		a = prerequisites[i][0];
		b = prerequisites[i][1];
	//	printf(" a %d, b %d ", a, b);
		node[a].val = a;
		node[a].parent_list = NULL;
		node[b].val = b;
		node[b].parent_list = NULL;
	}
	for(i=0; i<prerequisitesSize; i++)
	{
		a = prerequisites[i][0];
		b = prerequisites[i][1];
		if(a==b)
			return 0;
		bfs_start = 0;
		bfs_end =0;
		bfs[bfs_end] = a;
		visit_count++;
		visited[a] = visit_count;
		while(bfs_start <= bfs_end)
		{
			current_node = bfs[bfs_start];
			//		printf(" current_node %d ", current_node);
			bfs_start++;
			temp_parent = node[current_node].parent_list;
			while(temp_parent != NULL)
			{
				printf(" temp_parent %d ", temp_parent->val);
				if(temp_parent->val == b)
				{
					return 0;
				}
				if(visited[temp_parent->val] != visit_count)
				{
					bfs_end++;
					bfs[bfs_end] = temp_parent->val;
					visited[temp_parent->val] = visit_count;
				}
				temp_parent = temp_parent->next;
			}
		}
		if(node[b].parent_list == NULL)
		{
			parent_count++;
			parent[parent_count].val = a;
			parent[parent_count].next = NULL;
			node[b].parent_list = &parent[parent_count];
		}
		else
		{

			temp_parent = node[b].parent_list;
			//		printf(" temp_parent %d ", temp_parent->val);
			while(temp_parent->next != NULL)
			{
				temp_parent = temp_parent->next;
			}
			parent_count++;
			parent[parent_count].val = a;
			parent[parent_count].next = NULL;
			temp_parent->next = &parent[parent_count];
		}

	}
/*
	for(i =0; i<prerequisitesSize+1; i++)
	{
		temp_parent = node[i].parent_list;
		printf("\nnode %d parent  %d", node[i].val,temp_parent!=NULL?temp_parent->val:-1);
	}
*/
	return ret;
}

int main(void)
{
	int prerequisites[MAX_PREREQUISITES][2];
	int prerequisitesSize = 5;
	int prerequisitesColSize = 2;
	prerequisites[0][0] = 1;
	prerequisites[0][1] = 2;
	prerequisites[1][0] = 1;
	prerequisites[1][1] = 3;
	prerequisites[2][0] = 1;
	prerequisites[2][1] = 4;
	prerequisites[3][0] = 2;
	prerequisites[3][1] = 5;
	prerequisites[4][0] = 2;
	prerequisites[4][1] = 1;

	printf("\nOutput %d\n", canFinish(5, prerequisites, prerequisitesSize, &prerequisitesColSize));
	printf("\nCourse Schedule\n");
	return 0;
}
