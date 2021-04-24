#include<iostream>
#include<algorithm>

using namespace std;

typedef struct node_s
{
	int first;
	int second;
}node_t;

void show_arr(int arr[], int size_arr)
{
	cout<<"\nElements of arr are:\n";
	for(int i =0; i<size_arr; i++)
	{
		cout<<arr[i]<<" ";
	}
}

int compare_int(int a, int b)
{
	return a>b;
}

int compare_node(node_t a, node_t b)
{
	return a.first>b.first;
}

void show_node_arr(node_t node_arr[], int node_arr_size)
{
	cout<<"\n Elements of node arr are: \n";
	for(int i =0; i<node_arr_size; i++)
	{
		cout<<"first "<<node_arr[i].first<<" second "<<node_arr[i].second<<endl;
	}
	return;
}

int main(void)
{
	int arr[] = {10, 5, 20, 36, 3, 2, 8, 100};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	sort(arr, arr+arr_size, compare_int);

	show_arr(arr, arr_size);

	node_t node_arr[] = {{1,10}, {50, 20}, {3, 30}, {100, 40}};

	int node_arr_size = sizeof(node_arr)/sizeof(node_arr[0]);

	sort(node_arr, node_arr + node_arr_size, compare_node );
	show_node_arr(node_arr, node_arr_size);
	cout<<"\n\n Program to implement sort function\n";
	return 0;
}
