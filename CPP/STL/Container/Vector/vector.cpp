#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	vector<int>int_first;
	vector<int>int_second(4,100);
	vector<int>int_third(int_second);

	vector<char>char_first;

	int_first.push_back(101);
	int_first.push_back(102);

	int_second.push_back(201);
	int_second.push_back(202);

	int_third = int_second;
	int_third.push_back(301);
	int_third.push_back(302);
	int_third.push_back(int_second[2]);

	cout<<"\n"<<"int Capacity "<<int_first.capacity();
	cout<<"\n"<<"int Max Size "<<int_first.max_size();
	cout<<"\n"<<"char Max Size "<<char_first.max_size();

	cout<<"\n"<<int_third[int_third.size()+1]<<"\n";

	cout<<"\nelement at index 3 : "<<*(&int_third[3]);
	cout<<"\nelement at 3 : "<<int_third.at(3);
	cout<<"\nfront element : "<<int_third.front();
	cout<<"\nback lement : "<<int_third.back();

	int* int_prt = int_third.data();
	cout<<"\nelement at 3 : "<<int_prt[4];

	int_third.assign(4, 400);
	int_third.insert(int_third.end(), 200);

	int_first.swap(int_second);
	int_third.emplace(int_third.end(), 300);

	cout<<"\n"<<"Vector int_first contains :"<<endl;
	for(auto v : int_first)
		cout<<v<<" ";
	cout<<endl;
	cout<<"Vector int_second contains :"<<endl;
	for(auto& v : int_second)
	{
		cout<<v<<" ";
	}
	cout<<endl;
	vector<int>::iterator it;
	cout<<"Vector int_second contains :"<<endl;
	for(it = int_second.begin(); it != int_second.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	for(auto it = int_second.rbegin(); it != int_second.rend(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"Vector int_third contains :"<<endl;
	for(auto& v : int_third)
		cout<<v<<" ";

	cout<<endl;

	cout<<endl<<"Program to implement vector functions"<<endl;
	return 0;
}
