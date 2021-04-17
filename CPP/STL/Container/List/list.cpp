#include<iostream>
#include<list>

using namespace std;

typedef struct top_s
{
	int frequency;
	string sentence;
} top_t;

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

bool compare_function(string str1, string str2)
{
	cout<<"\nstr1 "<<str1<<" str2 "<<str2;
	cout<<"\n string compare "<<str1.compare(str2);
	return str1.compare(str2)<0?1:0;
}

bool compare_sentence(top_t* sen1, top_t* sen2)
{
	if(sen1->frequency == sen2->frequency)
		return sen1->sentence.compare(sen2->sentence)<0?1:0;
	return sen1->frequency>sen2->frequency?1:0;
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

	list<string>string_list = {"a", "abcd", "ab"};
	string_list.push_back("abc");
	for(auto& s :string_list)
	{
		cout<<s<<" ";
	}
	string_list.sort(compare_function);
	cout<<"\n";
	for(auto& s :string_list)
	{
		cout<<s<<" ";
	}
	top_t sentence_1;
	sentence_1.frequency = 5;
	sentence_1.sentence = "i love you";
	top_t sentence_2;
	sentence_2.frequency = 2;
	sentence_2.sentence = "icad";
	top_t sentence_3;
	sentence_3.frequency = 2;
	sentence_3.sentence = "iced";

	top_t sentence_4;
	sentence_4.frequency = 5;
	sentence_4.sentence = "ignor";

	list<top_t*>top_list;
	top_list.push_back(&sentence_1);
	top_list.push_back(&sentence_3);
	top_list.push_back(&sentence_2);
	top_list.push_back(&sentence_4);

	for(auto& t : top_list)
	{
		cout<<"\n frequency "<<t->frequency<<" sentence "<<t->sentence;
	}

	top_list.sort(compare_sentence);
	for(auto& t : top_list)
	{
		cout<<"\n frequency "<<t->frequency<<" sentence "<<t->sentence;
	}

	cout<<"\nProgram to implement function's of list container\n";
	return 0;
}
