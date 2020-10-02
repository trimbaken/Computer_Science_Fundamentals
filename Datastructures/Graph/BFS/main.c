#include<stdio.h>

int input[4][4] ={ 	{0,1,1,0},
			{0,0,1,0},
			{1,0,0,1},
			{0,0,0,1} };
int visited[4] ={0};
int queue[4] ={0};
int front =0;
int end =0;
int output[4] ={0};
int output_count =0;
void enqueue(int val)
{
	queue[end] = val;
	end++;
	output[output_count] = val;
	output_count++;
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
void bfs(int start)
{
	int curnt =0;
	int pop_element =0;
	int i =0;
	output_count =0;
	enqueue(start);
	visited[start] = 1;
	while(!is_empty())
	{
		curnt = dequeue();
		pop_element = 1;
		for(i =0; i<4; i++)
		{
			if(input[curnt][i] && !visited[i])
			{
				visited[i] = 1;
				enqueue(i);
			}
		}
	}
}

int main(void)
{
	int i =2;
	int j =0;

	while(!visited[i])
	{
		bfs(i);
		i = i%4;
		for(j=0; j<output_count;j++)
		{
			printf("%d \t",output[j]);
		}
	}
	printf("\n Program to get BFS of the given graph: \n");
	return 0;
}
