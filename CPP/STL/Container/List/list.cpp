#include<iostream>
#include<list>

using namespace std;

void print_list(list<int>int_list)
{
	cout<<"\n Elements present in list are: \n";
	for(auto l : int_list)
	{
		cout<<l<<" ";
	}
	cout<<"\n";
	return;
}

int main(void)
{
	list<int>int_list(4,100);

	int_list.push_back(101);
	int_list.push_front(201);
	int_list.push_back(102);
	int_list.push_front(202);

	cout<<"\n last element "<<int_list.back();
	cout<<"\n first element "<<int_list.front();
	cout<<"\n pop first element ";
	int_list.pop_front();
	cout<<"\n pop last element ";
	int_list.pop_back();

	print_list(int_list);
	cout<<"\n reverse list";
	int_list.reverse();

	print_list(int_list);
	int_list.push_front(302);
	int_list.push_front(1002);
	cout<<"\n sort list";
	int_list.sort();

	print_list(int_list);

	int_list.push_front(1002);
	cout<<"\n remove duplicate ";
	int_list.unique();
	print_list(int_list);

	list<int>int_list_1(4,200);

	int_list.merge(int_list_1);
	print_list(int_list);

	cout<<"\nProgram to implement function's of list container\n";
	return 0;
}
