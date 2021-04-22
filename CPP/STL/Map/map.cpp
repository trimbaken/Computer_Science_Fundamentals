#include<iostream>
#include<map>

using namespace std;

void show_map(map<int, int>int_map)
{
	cout<<"\nMap Elements are :\n";
	for(auto& map : int_map)
	{
		cout<<"\n Key "<<map.first<<" Value "<<map.second;
	}
	return;
}

int main(void)
{
	map<int, int>int_map;

	int_map.insert({1,10});
	int_map.insert({5,20});
	int_map.insert({3,30});
	int_map.insert({7,40});
	int_map.insert({2,50});

	show_map(int_map);

	cout<<"\n Find Value of 3 "<<int_map.find(3)->second;
	cout<<"\n Upper bound of 3 "<<int_map.upper_bound(3)->second;
	cout<<"\n Lower bound of 3 "<<int_map.lower_bound(3)->second;
	cout<<"\n Program to implement functionalities of Map\n";
	return 0;
}
