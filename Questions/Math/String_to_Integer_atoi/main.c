#include<stdio.h>
#define MAX_NEGATIVE 2147483648
#define MAX_POSITIVE 2147483647

int myAtoi(char * s){
	int ret =0;
	int t[200];
	int t_count =0;
	int long long ret_long =0;
	int long long m =1;
	int i =0;
	char c;
	int sign =1;
	int is_sign_found =0;
	int is_zero_found =0;

	if(s[i] != '-' && s[i] != '+' && s[i] >= 'a' && s[i] <= 'z' || s[i] == '.')
	{
		return ret;
	}
	while(s[i] != '\0' && t_count <12)
	{
		c = s[i];
		if(t_count == 0 && (c >= 'a' && c <= 'z'))
		{
			return 0;
		}
		if(t_count >0 && (c == '+' || c == '-' || c == ' ' || (c >= 'a' && c <= 'z' ))) // stop reading if non digit is found after number
		{
			break;
		}
		if (((is_sign_found == 1 || is_zero_found == 1 || t_count > 0) && (c == '+' || c == '-')))
		{
			return 0;
		}
		if((is_sign_found == 1 || is_zero_found == 1 || t_count >0) && ((c >= 'a' && c<='z') || c == '.'  || c == ' ') )
		{
			break;
		}
		else if(c == '-')
		{
			sign = -1;
			is_sign_found=1;
		}
		else if(c =='+')
		{
			sign = 1;
			is_sign_found=1;
		}
		else if(t_count == 0 && c=='0')
		{
			t_count =0;
			is_zero_found = 1;
		}
		else if(c >= '0' && c <= '9')
		{
			t[t_count] = c-'0';
			t_count++;
		}
		i++;
	}
	if(t_count >= 11)
	{
		if(sign == -1)
		{
			ret = 0-MAX_NEGATIVE;
		}
		else
		{
			ret = MAX_POSITIVE;
		}
		return ret;
	}
	for(i=t_count-1; i>=0; i--)
	{
		ret_long += m*t[i];
		m *= 10;
	}
	if(sign == 1 && ret_long > MAX_POSITIVE)
	{
		ret = MAX_POSITIVE;
	}
	else if(sign == -1 && ret_long > MAX_NEGATIVE)
	{
		ret = 0- MAX_NEGATIVE;
	}
	else
	{
		if(sign == -1)
		{
			ret = 0-ret_long;
		}
		else
		{
			ret = ret_long;
		}
	}
	return ret;
}

int main(void)
{
	char s[200] = "words and 987";

	printf("\n Integer is %d \n", myAtoi(s));
	char s1[200] = "3.2255";
	printf("\n Integer is %d \n", myAtoi(s1));
	char s2[200] = "9842 wodrd is ";
	printf("\n Integer is %d \n", myAtoi(s2));
	char s3[200] = "-5434";
	printf("\n Integer is %d \n", myAtoi(s3));
	char s4[200] = "+4645";
	printf("\n Integer is %d \n", myAtoi(s4));
	char s5[200] = "+-4645";
	printf("\n Integer is %d \n", myAtoi(s5));
	char s6[200] = "00000-42a1234";
	printf("\n Integer is %d \n", myAtoi(s6));
	char s7[200] = "    +0a32";
	printf("\n Integer is %d \n", myAtoi(s7));
	char s8[200] = "   +0 123";
	printf("\n Integer is %d \n", myAtoi(s8));
	char s9[200] = "-5-";
	printf("\n Integer is %d \n", myAtoi(s9));
	char s10[200] = " b11228552307";
	printf("\n Integer is %d \n", myAtoi(s10));
	printf("\nProgram to extract integer present in input string\n");
	return 0;
}
