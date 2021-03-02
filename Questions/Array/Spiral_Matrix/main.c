#include<stdio.h>

#define MAX_LEN 12
#define LEFT 0
#define RIGHT 1
#define UP 3
#define DOWN 4

int output[MAX_LEN*MAX_LEN];
int visited[MAX_LEN][MAX_LEN];
int test_case_number =0;

struct node
{
	int row;
	int col;
	int direction;
};

int* spiralOrder(int matrix[MAX_LEN][5], int matrixSize, int* matrixColSize, int* returnSize){
	int num_of_row;
	int num_of_col;
	int output_count =0;
	int row =0;
	int col =0;
	int visited_row =0;
	int visited_col =0;
	int i=0;
	int j=0;
	int direction =0;
	struct node current_node;

	test_case_number++;
	num_of_row = matrixSize;
	num_of_col = *matrixColSize;

	for(i =0; i<= num_of_col; i++)
	{
		visited[0][i] = test_case_number;
		visited[num_of_row+1][i] = test_case_number;
	}
	for(i =0; i<= num_of_row; i++)
	{
		visited[i][0] = test_case_number;
		visited[i][num_of_col+1] = test_case_number;
	}
	printf("\nInput Matrix\n");
	for(i =0; i<num_of_row; i++)
	{
		printf("\n");
		for(j =0; j<num_of_col; j++)
		{
			printf("%d ", matrix[i][j]);
		}
	}
	current_node.row = 0;
	current_node.col = 0;
	current_node.direction = RIGHT;
	direction = current_node.direction;
	while(1)
	{
		printf("\n current_node.direction %d %d \n", current_node.direction, matrix[current_node.row][current_node.col]);
		output[output_count] = matrix[current_node.row][current_node.col];
		output_count++;
		row = current_node.row;
		col = current_node.col;
		visited_row = row+1;
		visited_col = col+1;
		visited[visited_row][visited_col] = test_case_number;
		if(current_node.direction == RIGHT)
		{
			if(visited[visited_row][visited_col+1] != test_case_number)
			{
				current_node.row = row;
				current_node.col = col+1;
			}
			else if(visited[visited_row+1][visited_col] != test_case_number)
			{
				current_node.row = row+1;
				current_node.col = col;
				current_node.direction = DOWN;
			}
			else
				break;
		}
		if(current_node.direction == LEFT)
		{
			if(visited[visited_row][visited_col-1] != test_case_number)
			{
				current_node.col = col-1;
			}
			else if(visited[visited_row-1][visited_col] != test_case_number)
			{
				current_node.row = row-1;
				current_node.direction = UP;
			}
			else
				break;
		}
		if(current_node.direction == UP)
		{
			if(visited[visited_row-1][visited_col] != test_case_number)
			{
				current_node.row = row-1;
			}
			else if(visited[visited_row][visited_col+1] != test_case_number)
			{
				current_node.col = col+1;
				current_node.direction = RIGHT;
			}
			else
				break;
		}
		if(current_node.direction == DOWN)
		{
			if(visited[visited_row+1][visited_col] != test_case_number)
			{
				current_node.row = row+1;
			}
			else if(visited[visited_row][visited_col-1] != test_case_number)
			{
				current_node.col = col-1;
				current_node.direction = LEFT;
			}
			else
				break;
		}
	}
	*returnSize = output_count;
	return &output[0];
}

int main(void)
{
	int matrix[3][5] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int matrixColSize = 4;
	int returnSize = 0;
	int* ret = NULL;
	int i =0;

	ret = spiralOrder(matrix, 3, &matrixColSize, &returnSize);
	for(i =0; i<returnSize; i++)
	{
		printf("%d ", ret[i]);
	}
	printf("\nProgram to print input matrix in spriral form\n");
	return 0;
}
