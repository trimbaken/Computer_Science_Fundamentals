#include<iostream>
#include<set>
#include <bits/stdc++.h>

using namespace std;

void show_set(unordered_set< string > stringSet)
{
	for(auto& s : stringSet)
	{
		cout<<"\n "<<s;
	}
	cout<<"\n";
	return;
}

int main(void)
{
	unordered_set< string > stringSet;
	stringSet.insert("code");
	stringSet.insert("in");
	stringSet.insert("c++");
	stringSet.insert("is");
	stringSet.insert("fast");

	show_set(stringSet);
	string key = "slow";
	if (stringSet.find(key) == stringSet.end())
		cout << key << " not found" << endl << endl ;
	else
		cout << "Found " << key << endl << endl ;

	cout<<"\n Program to implement functionalities of unordered set\n";
	return 0;
}
