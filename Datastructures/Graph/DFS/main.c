#include<stdio.h>

int input[4][4] ={ 	{0,1,1,0},
			{0,0,1,0},
			{1,0,0,1},
			{0,0,0,1} };
int visited[4] ={0};
int stack[4] ={0};
int top =0;
int output[4] ={0};
int output_count =0;
void push(int val)
{
	stack[top] = val;
	top++;
	output[output_count] = val;
	output_count++;
}
int is_empty()
{
	if(!top)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int get_element()
{
	return stack[top-1];
}
void pop()
{
	top--;
}
void dfs(int start)
{
	int curnt =0;
	int pop_element =0;
	int i =0;
	output_count =0;
	push(start);
	visited[start] = 1;
	while(!is_empty())
	{
		curnt = get_element();
		pop_element = 1;
		for(i =0; i<4; i++)
		{
			if(input[curnt][i] && !visited[i])
			{
				visited[i] = 1;
				push(i);
				pop_element =0;
				break;
			}
		}
		if(pop_element)
		{
			pop();
		}
	}
}

int main(void)
{
	int i =2;
	int j =0;

	while(!visited[i])
	{
		dfs(i);
		i = i%4;
		for(j=0; j<output_count;j++)
		{
			printf("%d \t",output[j]);
		}
	}
	printf("\n Program to get DFS of the given graph: \n");
	return 0;
}
