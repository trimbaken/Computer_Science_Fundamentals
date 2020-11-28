#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

class Pizza {
	public:
		virtual void prepare() =0;
		virtual void bake() =0;
		virtual void cut() =0;
		virtual void box() =0;
};

class CheesePizza : public Pizza {
	public:
		void prepare()
		{
			cout<<"Preparing Cheese Piza "<<endl;
		}
		void bake()
		{
			cout<<"Bake Cheese Piza "<<endl;
		}
		void cut()
		{
			cout<<"Cut Cheese Piza "<<endl;
		}
		void box()
		{
			cout<<"Box pack Cheese Piza "<<endl;
		}

};

class VeggiePizza : public Pizza {
	public:
		void prepare()
		{
			cout<<"Preparing Veggie Piza "<<endl;
		}
		void bake()
		{
			cout<<"Bake Veggie Piza "<<endl;
		}
		void cut()
		{
			cout<<"Cut Veggie Piza "<<endl;
		}
		void box()
		{
			cout<<"Box pack Veggie Piza "<<endl;
		}

};

Pizza* order_pizza(char type[100])
{
	Pizza* pizza;
	cout<<"Type "<<type<<endl;
	if(!strcmp(type, "Cheese"))
	{
		CheesePizza cheesePizza;
		pizza = &cheesePizza;
	}
	else if(!strcmp(type, "Veggie"))
	{
		VeggiePizza veggiePizza;
		pizza = &veggiePizza;
	}
	else
	{
		cout<<"Invalid Type "<<type<<endl;
		return NULL;
	}
	pizza->prepare();
	pizza->bake();
	pizza->cut();
	pizza->box();

	return pizza;
}

int main(void)
{
	Pizza* cheese_pizza = order_pizza("Cheese");
	cout<<endl<<"Pizza Order"<<endl;
	Pizza* veggie_pizza = order_pizza("Veggie");

	cout<<endl<<"Program to Implement Pizza Shop "<<endl;
	return 0;
}
