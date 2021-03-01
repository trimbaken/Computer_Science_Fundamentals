#include<stdio.h>
#define MAX_SIZE 402
#define MAZ_LEN 201

char output[MAX_SIZE];

char * multiply(char* num1, char* num2){
	int output_count =0;
	int num1_array[MAZ_LEN];
	int num2_array[MAZ_LEN];
	int num1_len =0;
	int num2_len =0;
	int temp_array[MAX_SIZE] = {0};
	int carry =0;
	int i =0;
	int j =0;
	int k =0;
	int start_index =0;
	int end_index =0;
	int output_size =0;
	int temp =0;
	int zero_count =0;

//	output[output_count++] = '5';
//	output[output_count++] = '6';

	while(num1[num1_len] != '\0')
	{
		num1_array[num1_len] = num1[num1_len] - '0';
		if(num1_array[num1_len] == 0)
			zero_count++;
		num1_len++;
	}
	if(zero_count == num1_len)
	{
		output[output_count++] = '0';
		output[output_count] = '\0';
		return &output[0];
	}
	zero_count =0;
	while(num2[num2_len] != '\0')
	{
		num2_array[num2_len] = num2[num2_len] - '0';
		if(num2_array[num2_len] == 0)
			zero_count++;
		num2_len++;
	}
	if(zero_count == num2_len)
	{
		output[output_count++] = '0';
		output[output_count] = '\0';
		return &output[0];
	}

	printf("\n num1_len [%d], num2_len [%d]\n", num1_len, num2_len);
	/*
	output_size = num1_len+num2_len+1;
	for(i =0; i<output_size; i++)
	{
		temp_array[i] =0;
	}
	*/
	start_index =-1;
	for(i = num1_len-1; i>=0; i--)
	{
		carry =0;
		start_index++;
		k = start_index;
		for(j =num2_len-1; j>=0; j--)
		{
			temp = num1_array[i]*num2_array[j] + carry + temp_array[k];
			temp_array[k] = temp%10;
			carry = temp/10;
			k++;
		}
		if(carry>0)
		{
			temp_array[k] += carry;
			end_index = end_index<k?k:end_index;
		}
		else
		{
			end_index = end_index<(k-1)?(k-1):end_index;
		}
	}
	printf("\n end_index [%d]\n", end_index);
	for(i =end_index; i>=0; i--)
	{
		printf("%d ", temp_array[i]);
		output[output_count++] = '0' + temp_array[i];
	}
	output[output_count] = '\0';
	return &output[0];
}
int main(void)
{
	char num1[4] = "123";
	char num2[4] = "456";
	char* multiplication = multiply(num1, num2);

	printf("\nMultiplication of %s and %s is %s\n", num1, num2, multiplication);

	printf("\nProgram to Multiply Strings containing digits\n");
	return 0;
}
