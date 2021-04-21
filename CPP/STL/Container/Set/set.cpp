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

typedef struct person_s
{
	int id;
	string name;
}person_t;

auto compare_person = [](person_t p1, person_t p2){
	return p1.id<p2.id;
};

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

	set<person_t, decltype(compare_person)>person_set(compare_person);

	person_t p1;
	p1.id = 10;
	p1.name = "abc";
	person_t p2;
	p2.id = 5;
	p2.name = "abcd";
	person_t p3;
	p3.id = 20;
	p3.name = "abcde";

	person_set.insert(p1);
	person_set.insert(p2);
	person_set.insert(p3);

	for(auto p : person_set)
	{
		cout<<"\n id "<<p.id <<" name "<<p.name;
	}
	cout<<"\n Program to implement functionalities of STL Set\n";
	return 0;
}
