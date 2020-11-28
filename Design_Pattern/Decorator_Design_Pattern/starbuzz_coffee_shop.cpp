#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

class Beverage {
	private:
		char description[100];
	public:
		void set_description(char* new_description)
		{
			strcpy(description, new_description);
			/*
			int i =0;
			for(i=0; new_description[i] != '\0'; i++)
			{
				description[i] = new_description[i];
			}
			*/
		}
		void get_description()
		{
			cout<<endl<<"Beverage Description: "<<endl<<description<<endl;
		}
		virtual int cost()=0;

};

class HouseBlend : public Beverage {
	public:
		int cost()
		{
			int cost = 10;
			cout<<"Cost of HouseBlend Coffee is "<<cost<<"$"<<endl;
			return cost;
		}
};

class DarkRoast : public Beverage {
	public:
		int cost()
		{
			int cost = 15;
			cout<<"Cost of DarkRoast Coffee is "<<cost<<"$"<<endl;
			return cost;
		}
};

class Expresso : public Beverage {
	public:
		int cost()
		{
			int cost = 20;
			cout<<"Cost of Expresso Coffee is "<<cost<<"$"<<endl;
			return cost;
		}
};

class IngredientDecorator : public Beverage {
	public:
		void get_description() {
			cout<<"Ingredient Description"<<endl;
		}
};

class Milk : public IngredientDecorator {
	private:
		Beverage* wrappedBeverage;
	public:
		int cost()
		{
			int cost = wrappedBeverage->cost() + 10;
			cout<<wrappedBeverage->cost()<<endl;
			cout<<endl<<"Milk Cost"<< cost<<endl;
			return cost;
		}
		void get_description()
		{
			cout<<"Milk"<<endl;
		}
		void set_beverage(Beverage* new_beverage)
		{
			wrappedBeverage = new_beverage;
		}
};

class Mocha : public IngredientDecorator {
	private:
		Beverage* wrappedBeverage;
	public:
		int cost()
		{
			int cost = wrappedBeverage->cost() + 15;
			cout<<endl<<"Mocha Cost"<< cost<<endl;
			return cost;
		}
		void get_description()
		{
			cout<<"Mocha"<<endl;
		}
		void set_beverage(Beverage* new_beverage)
		{
			wrappedBeverage = new_beverage;
		}
};

class Soy : public IngredientDecorator {
	private:
		Beverage* wrappedBeverage;
	public:
		int cost()
		{
			int cost = wrappedBeverage->cost() + 20;
			cout<<endl<<"Soy Cost"<< cost<<endl;
			return cost;
		}
		void get_description()
		{
			cout<<"Soy"<<endl;
		}
		void set_beverage(Beverage* new_beverage)
		{
			wrappedBeverage = new_beverage;
		}
};

class Whip : public IngredientDecorator {
	private:
		Beverage* wrappedBeverage;
	public:
		int cost()
		{
			int cost = wrappedBeverage->cost() + 25;
			cout<<endl<<"Whipe Cost"<< cost<<endl;
			return cost;
		}
		void get_description()
		{
			cout<<"Whip"<<endl;
		}
		void set_beverage(Beverage* new_beverage)
		{
			wrappedBeverage = new_beverage;
		}
};



int main(void)
{
	HouseBlend house_blend;
	char description[100] = "House Blend Coffee contain coffe + milk";
	house_blend.set_description(description);
	house_blend.get_description();
	Milk milk;
	milk.set_beverage(&house_blend);
	milk.cost();
	Mocha mocha;
	mocha.set_beverage(&milk);
	Whip whip;
	whip.set_beverage(&mocha);
	int cost = whip.cost();
	cout<<"Cost of House Blen with Milk + Mocha + Whip "<<cost<<endl;


	DarkRoast dark_roast;
	char dark_roast_description[100] = "Dark Roast Coffee contain coffe + milk + Chocolate";
	dark_roast.set_description(dark_roast_description);
	dark_roast.get_description();
	milk.set_beverage(&dark_roast);
	Soy soy;
	soy.set_beverage(&milk);
	cost = soy.cost();
	cout<<"Cost of Dark Roast with Milk and Soy "<<cost<<endl;

	Expresso expresso;
	char expresso_description[100] = "Expresso Coffee contain coffe + milk + Sugar";
	expresso.set_description(expresso_description);
	expresso.get_description();
	whip.set_beverage(&expresso);
	milk.set_beverage(&whip);
	cost = whip.cost();
	cout<<"Cost of Expresso with Whip & Milk "<<cost<<endl;


	cout<<endl<<"Program to implement Starbuzz Coffee Shop operations"<<endl;
	return 0;
}
