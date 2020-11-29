#include<stdio.h>
#include<iostream>

using namespace std;

class Duck {
	public:
		virtual void fly() =0;
		virtual void quack() =0;
};

class MallardDuck : public Duck {
	public:
		void fly()
		{
			cout<<"Mallard Duck Fly for short time"<<endl;
		}
		void quack()
		{
			cout<<"Mallard Duck Quack "<<endl;
		}
};

class RedheaddDuck : public Duck {
	public:
		void fly()
		{
			cout<<"Redhead Duck Fly for long time"<<endl;
		}
		void quack()
		{
			cout<<"Mallard Duck Quack "<<endl;
		}
};

class RabbardDuck : public Duck {
	public:
		void fly()
		{
			cout<<"Rabbar Duck DOn't Fly"<<endl;
		}
		void quack()
		{
			cout<<"Rabbar Duck Dont't Quack "<<endl;
		}
};

class Turkey {
	public:
		virtual void gobble() =0;
		virtual void fly() =0;
};

class WildTurkey : public Turkey {
	public:
		void gobble()
		{
			cout<<"Gobble gobble"<<endl;
		}
		void fly()
		{
			cout<<"Fly for short duration "<<endl;
		}
};

class TurkeyAdapter : public Duck {
	public:
		Turkey* turkey;
		void set_turkey(Turkey* turkey)
		{
			this->turkey = turkey;
		}
		void fly()
		{
			turkey->fly();
		}
		void quack()
		{
			turkey->gobble();
		}
};

int main(void)
{
	Duck* duck;
	WildTurkey wild_turkey;
	TurkeyAdapter turkeyAdapter;
	turkeyAdapter.set_turkey(&wild_turkey);

	duck = &turkeyAdapter;

	duck->fly();
	duck->quack();
	cout<<" Program to implement Duck Simulation App"<<endl;

	return 0;
}
