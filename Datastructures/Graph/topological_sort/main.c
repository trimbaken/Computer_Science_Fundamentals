#include<stdio.h>

int input[6][6] ={      {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,1,0,0},
                        {0,1,0,0,0,0},
			{1,1,0,0,0,0},
			{1,0,1,0,0,0}};
int in_degree[6] ={0};
int output[6] = {0};
int output_count =0;
int visited[6] = {0};
int queue[6] ={0};
int front =0;
int end =0;
void set_in_degree()
{
	int i =0;
	int j =0;

	for(i =0; i<6; i++)
	{
		for(j=0; j<6; j++)
		{
			if(input[j][i])
			{
				in_degree[i] = in_degree[i]+1;
			}
		}
	}
}
void enqueue(int val)
{
	queue[end] = val;
	end++;
}
int is_empty()
{
	if(front == end)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int dequeue()
{
	int ret =0;
	ret = queue[front];
	front++;
	return ret;
}
void topo_sort()
{
	int i =0;
	int curnt =0;
	for(i =0; i<6; i++)
	{
		if(!in_degree[i])
		{
			output[output_count] = i;
			output_count++;
			visited[i] =1;
			enqueue(i);
		}
	}
	while(!is_empty())
	{
		curnt = dequeue();
		for(i =0; i<6; i++)
		{
			if(input[curnt][i])
			{
				if(in_degree[i])
				{
					in_degree[i] = in_degree[i] -1;
					if(!in_degree[i])
					{
						output[output_count] = i;
                        			output_count++;
					}
				}
				if(!visited[i])
				{
					enqueue(i);
					visited[i] =1;
				}
			}
		}
	}
}
int main(void)
{
	int i =0;
	set_in_degree();
	topo_sort();
	for(i=0; i<6; i++)
	{
		printf("%d \t", output[i]);
	}
	printf("\n Program to get topological sort: \n");
	return 0;
}
