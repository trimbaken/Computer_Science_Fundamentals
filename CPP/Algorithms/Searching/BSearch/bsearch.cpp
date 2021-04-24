#include<iostream>

using namespace std;

int compare(const void* a, const void* b)
{
	const int* i = (int*)a;
	const int* j = (int*)b;

	if(*i < *j)
		return -1;
	else if(*i > *j)
		return 1;
	else
		return 0;
}

int main(void)
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int a_size = sizeof(arr)/sizeof(arr[0]);
	int key =10;
	int *p1 = (int*)bsearch(&key, arr, a_size, sizeof(arr[0]), compare);
	if(p1)
		cout<<"\n element is present "<<*p1;
	else
		cout<<"\n element not present ";
	cout<<"\n Program to implement bsearch method\n";
	return 0;
}
