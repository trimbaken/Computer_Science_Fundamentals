#include<stdio.h>
#include<iostream>

using namespace std;

class Singleton {

	private:
		Singleton();
		static Singleton uniqueInstance;
	public:
		static Singleton get_instance()
		{
			cout<<"Create new object "<<endl;
			return uniqueInstance;
		}
};
int main(void)
{
//	Singleton sample;
	Singleton sample_singleton = Singleton::get_instance();
	cout<<endl<<"Program to implement Singleton Design Pattern "<<endl;

	return 0;
}
