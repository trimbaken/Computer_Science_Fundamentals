#include<stdio.h>

#define MAX_LEN 10000

char current_array[MAX_LEN];

char * countAndSay(int n){
	char previous_array[MAX_LEN] = "1";
	char* prev;
	int i =0;
	int j =0;
	int k =0;
	char digit;
	int count =0;
	int current_array_count =0;
	if(n ==1)
        {
            current_array[0] = '1';
            current_array[1] = '\0';
            return &current_array[0];
        }

	prev = &previous_array[0];
	for(i =2; i<= n; i++)
	{
		j =0;
		current_array_count =0;
		while(prev[j] != '\0')
		{
			printf("\n Prev %s\n", prev);
			count =0;
			digit = prev[j];
			printf("\n digit %c\n", digit);
			k = j;
			while( prev[k] != '\0' && prev[k] == digit)
			{
				printf("\n k %d\n", k);
				count++;
				k++;
			}
			while(count >0)
			{
				current_array[current_array_count] = '0' + (count%10);
				current_array_count++;
				count /= 10;
			}
			current_array[current_array_count] = digit;
			current_array_count++;
			if(prev[k] == '\0')
				break;
			else
				j = k;
		}
		current_array[current_array_count] = '\0';
		printf("\n Prev %s, Current %s\n", prev, current_array);
		k =0;
		while(current_array[k] != '\0')
		{
			previous_array[k] = current_array[k];
			k++;
		}
		previous_array[k] = '\0';
		prev = &previous_array[0];
	}
	return &current_array[0];
}


int main(void)
{
	printf("\nCount and Say %s\n", countAndSay(30));
	printf("\nProgram to implement Count and Say \n");
	return 0;
}
