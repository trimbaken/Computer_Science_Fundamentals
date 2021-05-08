#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a<b;
}
int main(void)
{
	// initializing vector of integers
	// for single occurrence
	vector<int> arr1 = {10, 15, 20, 25, 30, 35};

	// initializing vector of integers
	// for multiple occurrences
	vector<int> arr2 = {10, 15, 20, 20, 25, 30, 35};

	// initializing vector of integers
	// for no occurrence
	vector<int> arr3 = {10, 15, 25, 30, 35};

	/* binary_search */
	if(binary_search(arr1.begin(), arr1.end(), 20, compare))
		cout<<"\n 20 is present in arr1";
	else
		cout<<"\n 20 is not present in arr1";

	/* lower_bound - given index of first element >= search element */
	int lb = lower_bound(arr2.begin(), arr2.end(), 20, compare)- arr2.begin();
	if(arr2[lb] == 20)
	{
		cout<<"\n 20 is present at "<<lb;
	}
	else if(lb != arr2.size())
	{
		cout<<"\n 20 is not present and its next highest element is "<<arr2[lb];
	}
	else
	{
		cout<<"\n element not present in its lower bound is also not present";
	}
	/* upper_bound  - gives index of first element > search element*/
	int ub = upper_bound(arr2.begin(), arr2.end(), 20, compare)- arr2.begin();
	cout<<"\n upper_bound index "<<ub;
	if(ub>0 && arr2[ub-1] == 20)
	{
		cout<<"\n 20 is present at "<<ub;
	}
	else if(ub != arr2.size())
	{
		cout<<"\n 20 is not present and its next highest element is "<<arr2[ub];
	}
	else
	{
		cout<<"\n element not present in its upper bound is also not present";
	}

	cout<<"\n\n Program to implement Binary search using binary_search, lower_bound and upper_bound\n";
	return 0;
}
