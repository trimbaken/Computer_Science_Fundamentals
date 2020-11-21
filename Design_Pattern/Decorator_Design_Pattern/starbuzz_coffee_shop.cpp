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
			cout<<"Beverage Description "<<description<<endl;
		}
		virtual void cost() = 0;
};

class HouseBlend : public Beverage {
	public:
		void cost()
		{
			cout<<"Cost of HouseBlend Coffee is 10$ "<<endl;
		}
};

class DarkRoast : public Beverage {
	public:
		void cost()
		{
			cout<<"Cost of DarkRoast Coffee is 15$ "<<endl;
		}
};

class Expresso : public Beverage {
	public:
		void cost()
		{
			cout<<"Cost of Expresso Coffee is 20$ "<<endl;
		}
};



int main(void)
{
	HouseBlend house_blend;
	char description[100] = "House Blend Coffee contain coffe + milk";
	house_blend.set_description(description);
	house_blend.get_description();
	house_blend.cost();

	DarkRoast dark_roast;
	char dark_roast_description[100] = "Dark Roast Coffee contain coffe + milk + Chocolate";
	dark_roast.set_description(dark_roast_description);
	dark_roast.get_description();
	dark_roast.cost();

	Expresso expresso;
	char expresso_description[100] = "Expresso Coffee contain coffe + milk + Sugar";
	expresso.set_description(expresso_description);
	expresso.get_description();
	expresso.cost();

	cout<<endl<<"Program to implement Starbuzz Coffee Shop operations"<<endl;
	return 0;
}
