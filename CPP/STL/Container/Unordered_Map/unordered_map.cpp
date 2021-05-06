#include <iostream>
#include <unordered_map>
#include <vector>
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

	umap["abc"]++;
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
	return 0;
}
