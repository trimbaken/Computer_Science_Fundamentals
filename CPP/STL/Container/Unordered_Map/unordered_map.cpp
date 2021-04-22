#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<string, double> umap;

	umap["PI"] = 3.14;
	umap["root2"] = 1.414;
	umap["root3"] = 1.732;
	umap["log10"] = 2.302;
	umap["loge"] = 1.0;

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
	return 0;
}
