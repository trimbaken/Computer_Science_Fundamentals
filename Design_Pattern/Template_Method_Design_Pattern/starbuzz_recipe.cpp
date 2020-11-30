#include<stdio.h>
#include<iostream>

using namespace std;

class CoffeineBeverage {
	public:
		virtual void prepare() final // Method can't be overwrite by derived class
		{
			boil_water();
			brew();
			pure_in_cup();
			add_condiments();
		}
		void boil_water()
		{
			cout<<"Boil Water "<<endl;
		}
		virtual void brew()=0;
		void  pure_in_cup()
		{
			cout<<"Pure in Cup "<<endl;
		}
		virtual void add_condiments() =0;
};

class Tea : public CoffeineBeverage {
	public:
		void brew()
		{
			cout<<"Add tea into boiled water "<<endl;
		}
		void add_condiments()
		{
			cout<<"Add Sugar and Lemon"<<endl;
		}
};

class Coffee : public CoffeineBeverage {
	public:
		void brew()
		{
			cout<<"Dripping Coffee through filter "<<endl;
		}
		void add_condiments()
		{
			cout<<"Add Sugar and milk"<<endl;
		}
};

int main(void)
{
	Coffee coffee;
	cout<<endl<<"Prepare Coffee "<<endl;
	coffee.prepare();
	Tea tea;
	cout<<endl<<"Prepare Tea"<<endl;
	tea.prepare();
	cout<<endl<<"Program to implement template method design pattern "<<endl;

	return 0;
}
