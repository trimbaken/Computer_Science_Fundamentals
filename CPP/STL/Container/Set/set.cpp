#include<iostream>
#include<set>
using namespace std;

void show_set(set<int>int_set)
{
	cout<<"\n Elements of Set are:\n";
	for(auto &s : int_set)
	{
		cout<<s<<" ";
	}
	return;
}

int main(void)
{
	set<int>int_set;
	int_set.insert(10);
	int_set.insert(50);
	int_set.insert(30);
	int_set.insert(5);
	int_set.insert(100);
	int_set.insert(50);

	show_set(int_set);

	int_set.erase(50);
	show_set(int_set);

	set<int>::iterator itr;
	itr = int_set.find(300);
	cout<<"\n find "<<*itr;
	cout<<"\n find "<<*int_set.find(30);
	cout<<"\n lower bound "<<*int_set.lower_bound(7);
	cout<<"\n upper bound "<<*int_set.upper_bound(7);
	cout<<"\n Program to implement functionalities of STL Set\n";
	return 0;
}
