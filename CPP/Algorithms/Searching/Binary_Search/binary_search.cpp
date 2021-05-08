#include<iostream>
#include<algorithm>
using namespace std;

void show_a(int a[], int a_size)
{
	cout<<"\n Contents of a :\n";
	for(int i =0; i<a_size; i++)
	{
		cout<<" "<<a[i];
	}
	return;
}

int main(void)
{
	int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int a_size = sizeof(a)/sizeof(a[0]);
	show_a(a, a_size);
	sort(a, a+a_size);
	show_a(a, a_size);
	cout<<binary_search(a, a+a_size, 9);
	if(binary_search(a, a+a_size, 10))
		cout<<"\n element is present";
	else
		cout<<"\n element is not present";
	cout<<"\n Program to implement binary search\n";
	return 0;
}
