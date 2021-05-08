#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

int main()
{
	unordered_map<string, double> umap;

	umap["PI"] = 3.14;
	umap["root2"] = 1.414;
	umap["root3"] = 1.732;
	umap["log10"] = 2.302;
	umap["loge"] = 1.0;
	umap["PI"] = 3.15;
	umap.insert(pair<string, double>("HI", 3.56));

	umap.insert(make_pair("e", 2.718));

	string key = "PI";

	if (umap.find(key) == umap.end())
		cout << key << " not found\n\n";

	else
		cout << "Found " << key << "\n\n";

	key = "lambda";
	if (umap.find(key) == umap.end())
		cout << key << " not found\n";
	else
		cout << "Found " << key << endl;

	umap["abc"]++; // initialized with 0
	umap["abc"]++;
	umap["abc"]++;
	umap["abc"]++;
	unordered_map<string, double>:: iterator itr;
	cout << "\nAll Elements : \n";
	for (itr = umap.begin(); itr != umap.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << endl;
	}

	auto it = umap.begin();

	// stores the bucket number of the key k
	int number = umap.bucket(it->first);
	cout << "The bucket number of key " << it->first << " is " << number<<endl;

	unordered_map<string, vector<string> >str_umap;

	str_umap["abc"].push_back("cba");
	str_umap["abc"].push_back("bca");
	str_umap["abc"].push_back("cab");
	str_umap["aac"].push_back("caa");
	str_umap["aac"].push_back("aca");
	str_umap["aac"].push_back("aac");

	for(auto& str_key: str_umap)
	{
		cout<<"\n Key : "<<str_key.first << ", Value : ";
		for(auto str_val : str_key.second)
		{
			cout<<" "<<str_val;
		}
		cout<<endl;
	}
	unordered_map<int, int>u_int_map;
	u_int_map[3] = 1;
	for(auto& a: u_int_map)
		cout<<a.second;

	list<pair<string, string>>page_list;
	list<pair<string, string>>:: iterator page_list_itr;

	unordered_map<string, list<pair<string, string>>:: iterator> page_umap;

	page_list.push_front(pair<string, string>("page_1_key", "page_1_value"));
	page_list_itr = page_list.begin();
	page_umap["page_1_key"] = page_list_itr;
	page_list.push_front(pair<string, string>("page_2_key", "page_2_value"));
	page_list_itr = page_list.begin();
	page_umap["page_2_key"] = page_list_itr;
	page_list.push_front(pair<string, string>("page_3_key", "page_3_value"));
	page_list_itr = page_list.begin();
	page_umap["page_3_key"] = page_list_itr;

	page_list_itr = page_umap["page_1_key"];
	cout<<"\n "<<page_list_itr->first<<" "<<page_list_itr->second;

	page_list.remove(*page_list_itr);
	page_umap.erase("page_1_key");

	if(page_umap.find("page_1_key") != page_umap.end())
	{
		cout<<"\n Page 1 found";
	}
	else
	{
		cout<<"\n Page 1 not found";
	}
	for(auto &l : page_list)
	{
		cout<<"\n "<<l.first<<" "<<l.second;
	}

	page_list.push_front(pair<string, string>("page_1_key", "page_1_value"));
	page_list_itr = page_list.begin();
	page_umap["page_1_key"] = page_list_itr;
	if(page_umap.find("page_1_key") != page_umap.end())
	{
		cout<<"\n Page 1 found";
	}
	else
	{
		cout<<"\n Page 1 not found";
	}
	for(auto &l : page_list)
	{
		cout<<"\n "<<l.first<<" "<<l.second;
	}


	cout<<"\n\n Program to implement functionalities of unordered map\n\n";
	return 0;
}
