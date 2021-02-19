#include<stdio.h>

#define MAX_SIZE 2500
#define max(a,b) a>b?a:b

typedef struct node {
	int row;
	int col;
}node;

node dfs_node[MAX_SIZE];
int visited[50][50];
int visited_count;
int A[4] = {-1, 1, 0, 0};
int B[4] = {0, 0, -1, 1};

int dfs(int row, int col, int grid[50][50], int gridSize, int gridColSize)
{
	int ret =0;
	visited_count++;
	int dfs_count =-1;
	int i =0;
	int j =0;
	int a =0;
	int b =0;
	int x =0;
	int y =0;

//	printf("\n row %d %d %d ", row, col, grid[row][col]);
	dfs_count++;
	dfs_node[dfs_count].row = row;
	dfs_node[dfs_count].col = col;
	visited[row][col] = visited_count;
	grid[row][col] = 0;
	ret++;

	while(dfs_count >=0)
	{
		x = dfs_node[dfs_count].row;
		y = dfs_node[dfs_count].col;
//		printf(" %d %d %d ", x, y, grid[x][y]);
		dfs_count--;
		for(i =0; i<4; i++)
		{
			a = x+A[i];
			b = y+B[i];
//			printf(" %d %d ", a, b);
			if(a >= 0 && a<gridSize && b>=0 && b<gridColSize && grid[a][b] == 1 && visited[a][b] != visited_count)
			{
				ret++;
				dfs_count++;
				dfs_node[dfs_count].row = a;
				dfs_node[dfs_count].col = b;
				visited[a][b] = visited_count;
				grid[a][b] =0;
			}
		}
	}
	printf("\nret [%d]\n",ret);
	return ret;
}


int maxAreaOfIsland(int grid[50][50], int gridSize, int* gridColSize){
	int i =0;
	int j =0;
	int ret =0;
	int temp =0;
	visited_count =0;
	for(i =0; i<50; i++)
	{
		for(j=0;j<50;j++)
		{
			visited[i][j] =0;
		}
	}

	for(i =0; i<gridSize; i++)
	{
		printf("\n");
		for(j =0; j<gridColSize[i]; j++)
		{
			printf("%d ,", grid[i][j]);
			if(grid[i][j] == 1)
			{
				temp = dfs(i,j, grid, gridSize, gridColSize[i]);
				ret = max(ret, temp);
			}
		}
	}

	return ret;
}

int main(void)
{
	int input[50][50] = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
				{0,0,0,0,0,0,0,1,1,1,0,0,0},
				{0,1,1,0,1,0,0,0,0,0,0,0,0},
				{0,1,0,0,1,1,0,0,1,0,1,0,0},
				{0,1,0,0,1,1,0,0,1,1,1,0,0},
				{0,0,0,0,0,0,0,0,0,0,1,0,0},
				{0,0,0,0,0,0,0,1,1,1,0,0,0},
				{0,0,0,0,0,0,0,1,1,0,0,0,0}};
	int gridColSize[13] = {13,13,13,13,13,13,13,13,13,13,13,13,13};

	printf("\n Max Area of Island is %d\n", maxAreaOfIsland(input, 8, gridColSize));

	printf("\nProgram to find max area island in 2d array\n");
	return 0;
}
