#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main(void)
{
	fstream file;
	string line;

	file.open("file_handling.cpp", ios::in);

	while(file)
	{
		getline(file, line);
		cout<<"\n"<<line;
	}
//	file.seekg(0, ios::beg);
	file.close();

	file.open("file_handling.cpp", ios::app);
	line = "/* End of Program */";
//	file<<line<<endl;
	file.close();
	file.open("file_handling.cpp", ios::in);
	while(file)
	{
		getline(file, line);
		stringstream ss(line);
		string word;
		cout<<"\n";
		while(ss >> word)
			cout<<word<<" ";
//		cout<<"\n"<<line;
	}

	cout<<"\nProgram to handle file in cpp\n";
	return 0;
}

/* End of Program */
/* End of Program */
