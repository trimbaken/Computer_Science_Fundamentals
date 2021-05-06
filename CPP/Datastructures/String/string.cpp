#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

void show_string(string str)
{
	cout<<"\n string is "<<str<<endl;
}
void new_line()
{
	cout<<"\n";
}
bool str_comapre(char a, char b)
{
	return a>b;
}
int main(void)
{
	string str = "Program Of TheDay 100.100";
	string str1;
	str1 = str.substr(2,3);
	cout<<str.substr(2, 3);
	cout<<"\n"<<str1;

	int str_size = str.length();

	cout<<"\n str_size "<<str_size<<endl;

	for(int i =0; i<str_size; i++)
	{
		cout<<str[i];
	}
	char str2[50];

	str.copy(str2, 5, 0); // dest, lenght, start index
	cout<<"\n sub tring "<<str2;

	string str3 = str + " # " + str2; // Concadinate two string
	cout<<"\n str3 "<<str3;

	cout<<"\n back char "<< str3.back();
	cout<<"\n front char "<<str3.front();

	str.append("a#B");
	str.append(str2);
	str.push_back('&');

	show_string(str);

	str.insert(4, str2); // insert given string at given index
	show_string(str);

	int found = str.find("a",11);
	cout<<"\n found at index "<<found;


	cout<<"\n strsub(pos) "<<str.substr(5); // Sub string from given position to the end

	string s = "100.10.1.001.1.12.0.";
	show_string(s);
	found =0;
	found = s.find('.', found);
	cout<<"\n all pos of . \n";
	int next =0;
	while(found != -1)
	{
		next = s.find('.', found+1);
//		cout<<"\n found "<<found<<" next "<<next<<endl;;
//		cout<<" "<<s.substr(found+1, next-found-1);
		string sub_str;
		sub_str= s.substr(found+1, next-found-1);
		stringstream ss(sub_str);
		int n =0;
		ss >> n;
		cout<<" n "<<n<<endl;;
		found = next;
	}

	string s1 = "/path/to/file/file.txt";

	show_string(s1);

	found = s1.find_first_of('/');
	cout<<" "<<s1.substr(0, found);
	while(found != -1)
	{
		next = s1.find_first_of('/', found +1);
		cout<<" "<<s1.substr(found+1, next-found-1);
		found = next;
	}

	found = s1.find_last_of('/');
	while(found != -1)
	{
		cout<<"\n"<<s1.substr(found+1);
		s1 = s1.substr(0, found);
		found = s1.find_last_of('/');
	}

	string s2 = ".100.2.10.200..30..";
	int index =0;
	show_string(s2);
	new_line();
	while(index < s2.length())
	{
		found = s2.find('.',index);
		if(found != -1)
		{
			cout<<" "<<s2.substr(index, found-index);
			index = found+1;
			s2[found] = ' ';
//			s2.insert(found, "*");
		}
		else
		{
			cout<<" "<<s2.substr(index);
			index = s2.length();
		}
	}
	show_string(s2);
	index =0;
	while(index < s2.length())
	{
		found = s2.find(' ', index);
		if(found != -1)
		{
			if(index != found)
				cout<<" "<<s2.substr(index, found-index);
			index = found+1;
		}
		else
		{
			cout<<" "<<s2.substr(index);
			index = s2.length();
		}
	}
	show_string(s2);
	istringstream ss(s2);
	string word;
	int n;
	while(ss >> word)
	{
		stringstream ssi(word);
		ssi >> n;
		n++;
		cout<<"\n"<<word;
		cout<<"\n"<<n;
	}
	string s3 = "/path/to/file/file.txt";
	show_string(s3);
	sort(s3.begin(), s3.end(), str_comapre);
	show_string(s3);
	cout<<"\n Program to implement functions of string \n";
	return 0;
}
