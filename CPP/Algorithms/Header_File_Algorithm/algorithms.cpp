#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void show_int_vec(vector<int> int_vec)
{
	cout<<"\n Elements of int vector are: \n";
	for(auto& i : int_vec)
	{
		cout<<" "<<i;
	}
	return;
}

bool compare(int a, int b)
{
	return a<b;
}

bool char_compare(char a, char b)
{
	return a<b;
}

int main(void)
{
	vector<int> int_vec = {10, 20, 5, 23 ,42 , 15};

	show_int_vec(int_vec);
	sort(int_vec.begin(), int_vec.end(), compare);
	show_int_vec(int_vec);
	reverse(int_vec.begin(), int_vec.end());
	show_int_vec(int_vec);
	int max = *max_element(int_vec.begin(), int_vec.end());
	cout<<"\n "<<max;
	int min = *min_element(int_vec.begin(), int_vec.end());
	cout<<"\n "<<min;

	string str = "adbcxyz chd";
	reverse(str.begin(), str.end());
	cout<<"\n Str "<<str;

	sort(str.begin(), str.end(), char_compare);
	cout<<"\n Str "<<str;

	char max_char = *max_element(str.begin(), str.end());
	cout<<"\n Max char "<<max_char;
	char min_char = *min_element(str.begin(), str.end());
	cout<<"\n Min char "<<min_char;

	cout<<"\n\nProgram to implement pre-defined functions of Algorithm\n";
	return 0;
}
