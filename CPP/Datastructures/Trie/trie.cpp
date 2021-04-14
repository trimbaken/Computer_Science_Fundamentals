#include<iostream>
#include <list>

using namespace std;

#define MAX_CHILD 27

class Trie
{
public:
	char val;
	bool is_leaf;
	typedef struct bfs_node_s
	{
		Trie* trie_node;
		string value;
	}bfs_node_t;

	Trie* child[MAX_CHILD];

	Trie()
	{
		this->val = '/';
		this->is_leaf = false;
		for(int i =0; i<MAX_CHILD; i++)
		{
			this->child[i] = NULL;
		}
	}
	Trie(char val)
	{
		this->val = val;
		this->is_leaf = false;
		for(int i =0; i<MAX_CHILD; i++)
		{
			this->child[i] = NULL;
		}
	}
	Trie(char val, bool is_leaf)
	{
		this->val = val;
		this->is_leaf = is_leaf;
		for(int i =0; i<MAX_CHILD; i++)
		{
			this->child[i] = NULL;
		}
	}
	void insert(string val)
	{
		int child_index = 0;
		int i =0;
		Trie* current = this;
		while(val[i] != '\0')
		{
			if(val[i] == ' ')
			{
				child_index = 26;
			}
			else
			{
				child_index = val[i] - 'a';
			}
			if(child_index <0 || child_index >= MAX_CHILD)
			{
				cout<<"Invalid value, enter value  a-b or space"<<endl;
				return;
			}
			if(current->child[child_index] == NULL)
			{
				current->child[child_index] = new Trie(val[i]);
			}
			current = current->child[child_index];
			i++;
		}
		current->is_leaf = true;
	}
	bool search(string val)
	{
		int child_index = 0;
		int i =0;
		Trie* current = this;
		while(val[i] != '\0')
		{
			if(val[i] == ' ')
			{
				child_index = 26;
			}
			else
			{
				child_index = val[i] - 'a';
			}
			if(child_index <0 || child_index >= MAX_CHILD)
			{
				cout<<"Invalid value, enter value  a-b or space"<<endl;
				return false;
			}
			if(current->child[child_index] == NULL)
			{
				cout<<"input string is not present current->val "<<current->val<<endl;
				return false;
			}
			current = current->child[child_index];
			i++;
		}
		return current != NULL?current->is_leaf?true:false:false;
	}
	bool delete_string(string val)
	{
		int child_index = 0;
		int i =0;
		Trie* current = this;
		while(val[i] != '\0')
		{
			if(val[i] == ' ')
			{
				child_index = 26;
			}
			else
			{
				child_index = val[i] - 'a';
			}
			if(child_index <0 || child_index >= MAX_CHILD)
			{
				cout<<"Invalid value, enter value  a-b or space"<<endl;
				return false;
			}
			if(current->child[child_index] == NULL)
			{
				cout<<"input string is not present current->val "<<current->val<<endl;
				return false;
			}
			current = current->child[child_index];
			i++;
		}
		current->is_leaf = false;
		return true;
	}
	bool print_trie()
	{
		int child_index = 0;
		int i =0;
		Trie* current = this;
		bfs_node_t bfs[1000];
		int bfs_count =0;

		bfs_node_t* current_bfs_node;
		bfs_node_t* new_bfs_node = &bfs[bfs_count];
		bfs_count++;
		new_bfs_node->trie_node = current;
		new_bfs_node->value = "";

		list<bfs_node_t* >bfs_list;
		bfs_list.push_back(new_bfs_node);

		while(!bfs_list.empty())
		{
			current_bfs_node = bfs_list.front();
			current = current_bfs_node->trie_node;
			for(int i =0; i<MAX_CHILD; i++)
			{
				if(current->child[i] != NULL)
				{
					new_bfs_node = &bfs[bfs_count];
					bfs_count++;
					new_bfs_node->trie_node = current->child[i];
					new_bfs_node->value.append(current_bfs_node->value);
					new_bfs_node->value.push_back(current->child[i]->val);

					bfs_list.push_back(new_bfs_node);
				}
			}
			if(current->is_leaf)
			{
				cout<<"Leaf Node "<<current_bfs_node->value<<endl;
			}
			bfs_list.pop_front();
		}
		return true;
	}

};
int main(void)
{
	Trie* trie_root = new Trie();
	cout<<"trie_root is leaf "<<trie_root->is_leaf<<endl;

	Trie* trie_root_1 = new Trie('a');
	cout<<"trie_root_1 val "<<trie_root_1->val<<endl;

	Trie* trie_root_2 = new Trie('b', true);
	cout<<"trie_root_2 val "<<trie_root_2->val<<endl;
	cout<<"trie_root_2 is leaf "<<trie_root_2->is_leaf<<endl;

	trie_root->insert("abc");
	cout<<"Search abc "<<trie_root->search("abc")<<endl;
	trie_root->delete_string("abc");
	cout<<"Search abc "<<trie_root->search("abc")<<endl;
	trie_root->insert("abc abc");
	cout<<"Search abcabc "<<trie_root->search("abc abc")<<endl;
	trie_root->insert("abc");
	trie_root->insert("axx");
	trie_root->print_trie();
	cout<<"Program to Implement Trie Data Structure"<<endl;
	return 0;
}
