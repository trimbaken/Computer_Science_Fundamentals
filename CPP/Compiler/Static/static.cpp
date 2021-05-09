#include<iostream>

using namespace std;

void demo()
{
	static int count =0;

	cout<<" "<<count;
	count++;
}

class static_veriable_class
{
	public:
		static int i;
		static int j;
		int k;
		static_veriable_class()
		{
			cout<<"\n inside static_veriable_class constructor";
		};
		~static_veriable_class()
		{
			cout<<"\n inside static_veriable_class destructor\n";
		};
		static void static_function() {
			j =20;
			cout<<"\n inside static_function";
			cout<<"\n static_function : j "<<j;
		};

};

int static_veriable_class::i = 10;
int static_veriable_class::j = 10;
int main(void)
{

	for(int i =0; i<5; i++)
	{
		demo();
	}
	static_veriable_class obj1;
	static_veriable_class obj2;
	cout<<"\n obj1.i "<<obj1.i;
	cout<<"\n obj2.i "<<obj2.i;
	obj1.i = 1;
	obj2.i = 2;
	cout<<"\n obj1.i "<<obj1.i;
	cout<<"\n obj2.i "<<obj2.i;

	int x =0;
	if(x ==0)
	{
		static_veriable_class obj3;
		static static_veriable_class obj4;
	}
	static_veriable_class::static_function();
	obj2.static_function(); // Not recommended
	cout<<"\n\nProgram to analyze static veriable, function, class objects\n";
	return 0;
}
