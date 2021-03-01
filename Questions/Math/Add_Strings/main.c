#include<stdio.h>
#define MAX_SIZE 5102
#define MAZ_LEN  5102

char output[MAX_SIZE];

char * addStrings(char* num1, char* num2){
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
	int num1_zero_count =0;
	int num2_zero_count =0;

	while(num1[num1_len] != '\0')
	{
		num1_array[num1_len] = num1[num1_len] - '0';
		if(num1_array[num1_len] == 0)
			num1_zero_count++;
		num1_len++;
	}
	while(num2[num2_len] != '\0')
	{
		num2_array[num2_len] = num2[num2_len] - '0';
		if(num2_array[num2_len] == 0)
			num2_zero_count++;
		num2_len++;
	}
	if(num1_zero_count == num1_len && num2_zero_count == num2_len)
	{
		output[output_count++] = '0';
		output[output_count] = '\0';
		return &output[0];
	}
	carry =0;
	i = num1_len-1;
	j = num2_len-1;
	k =0;
	while(i>=0 || j>=0 )
	{
		temp = (i>=0?num1_array[i]:0) + (j>=0?num2_array[j]:0) + carry;
		carry = temp/10;
		temp_array[k] = temp%10;
		k++;
		i--;
		j--;
	}
	if(carry>0)
	{
		temp_array[k] = carry;
		k++;
	}
	for(i =k-1; i>=0; i--)
	{
		output[output_count++] = '0' + temp_array[i];
	}
	output[output_count] = '\0';
	return &output[0];
}
int main(void)
{
	char num1[4] = "999";
	char num2[4] = "999";
	char* multiplication = addStrings(num1, num2);

	printf("\nMultiplication of %s and %s is %s\n", num1, num2, multiplication);

	printf("\nProgram to Multiply Strings containing digits\n");
	return 0;
}
