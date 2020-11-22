#include<stdio.h>
#include<memory.h>
#include<iostream>

using namespace std;

class Beverage {
	private:
		char description[100];
		int milk;
		int soy;
		int mocha;
		int whip;
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

		int has_milk()
		{
			if(milk == 1)
				return 1;
			else
				return 0;
		}
		void set_milk()
		{
			milk =1;
		}
		int has_soy()
		{
			if(soy ==1)
				return 1;
			else
				return 0;
		}
		void set_soy()
		{
			soy =1;
		}
		int has_mocha()
		{
			if(mocha ==1)
				return 1;
			else
				return 0;
		}
		void set_mocha()
		{
			mocha =1;
		}
		int cost(){
			int cost = 0;
			if(has_milk())
				cost = cost + 10;
			if(has_soy())
				cost = cost + 5;
			if(has_mocha())
				cost = cost + 15;
			return cost;
		}
};

class HouseBlend : public Beverage {
	public:
		void cost()
		{
			int cost = Beverage::cost() + 10;
			cout<<"Cost of HouseBlend Coffee is "<<cost<<"$"<<endl;
		}
};

class DarkRoast : public Beverage {
	public:
		void cost()
		{
			int cost = Beverage::cost() + 15;
			cout<<"Cost of DarkRoast Coffee is "<<cost<<"$"<<endl;
		}
};

class Expresso : public Beverage {
	public:
		void cost()
		{
			int cost = Beverage::cost() + 20;
			cout<<"Cost of Expresso Coffee is "<<cost<<"$"<<endl;
		}
};



int main(void)
{
	HouseBlend house_blend;
	char description[100] = "House Blend Coffee contain coffe + milk";
	house_blend.set_description(description);
	house_blend.set_milk();
	house_blend.set_soy();
	house_blend.set_mocha();
	house_blend.get_description();
	house_blend.cost();

	DarkRoast dark_roast;
	char dark_roast_description[100] = "Dark Roast Coffee contain coffe + milk + Chocolate";
	dark_roast.set_description(dark_roast_description);
	dark_roast.set_milk();
	dark_roast.set_soy();
	dark_roast.get_description();
	dark_roast.cost();

	Expresso expresso;
	char expresso_description[100] = "Expresso Coffee contain coffe + milk + Sugar";
	expresso.set_description(expresso_description);
	expresso.set_mocha();
	expresso.get_description();
	expresso.cost();

	cout<<endl<<"Program to implement Starbuzz Coffee Shop operations"<<endl;
	return 0;
}
