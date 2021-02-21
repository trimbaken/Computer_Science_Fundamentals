#include<stdio.h>
#include<string.h>

#define MAX_LEN 10002

char ret[MAX_LEN] = "1229";

char * removeKdigits(char * num, int k){
	int len = 0;
	len = strlen(num);
	printf("\nnum [%s], len [%d], k [%d]\n", num, len,k);
	return ret;

}

int main(void)
{
	char num[MAX_LEN] = "1432219";
	char* output = NULL;
	int i =0;
	int k =0;
	k = 3;
	output = removeKdigits(num, k);
	while(output[i] != '\0')
	{
		printf("%c ", output[i]);
		i++;
	}
	printf("\nProgram to remove K digit from input string to get minimum value number\n");
	return 0;
}
