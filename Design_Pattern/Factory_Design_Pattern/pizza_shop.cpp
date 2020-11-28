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

class SimplePizzaFactory {
	public:
		Pizza* pizza ;
		Pizza* create_pizza(char type[100])
		{
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
			return pizza;
		}
};

class PizzaStore {
	public:
		SimplePizzaFactory pizzaFactory;
		void set_factory(SimplePizzaFactory new_factory)
		{
			this->pizzaFactory = new_factory;
		}
		void order_pizza(char type[100])
		{
			Pizza* pizza = pizzaFactory.create_pizza(type);
			pizza->prepare();
			pizza->bake();
			pizza->cut();
			pizza->box();
		}
};

int main(void)
{
	PizzaStore store;
	SimplePizzaFactory pizzaFactory;
	store.set_factory(pizzaFactory);
	cout<<endl<<"Pizza Order"<<endl;
	store.order_pizza("Cheese");
	cout<<endl<<"Pizza Order"<<endl;
	store.order_pizza("Veggie");

	cout<<endl<<"Program to Implement Pizza Shop "<<endl;
	return 0;
}
