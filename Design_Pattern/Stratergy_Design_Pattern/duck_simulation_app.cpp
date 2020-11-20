#include<stdio.h>
#include<iostream>

using namespace std;

class Duck {
	public:
		void swim()
		{
			cout<<"Duck swim in pool"<<endl;
		}
		void display()
		{
			cout<<"Display duck on screen"<<endl;
		}
		void fly()
		{
			cout<<"Duck fly in sky"<<endl;
		}
		void quack()
		{
			cout<<"Duck quack"<<endl;
		}
};

class MallardDuck : public Duck {
	public:
		void name()
		{
			cout<<"Duck Name : Mallard Duck"<<endl;
		}
};

class RedheaddDuck : public Duck {
	public:
		void name()
		{
			cout<<"Duck Name : Redhead Duck"<<endl;
		}
};

class RabbardDuck : public Duck {
	public:
		void name()
		{
			cout<<"Duck Name : Rabbar Duck"<<endl;
		}
		void fly()
		{
			cout<<"Rabbar Duck don't fly"<<endl;
		}
};


int main(void)
{
	Duck duck;
	duck.display();
	cout<<endl;

	MallardDuck mallardDuck;
	mallardDuck.name();
	mallardDuck.display();
	mallardDuck.swim();
	mallardDuck.fly();
	mallardDuck.quack();
	cout<<endl;

	RedheaddDuck redheaddDuck;
	redheaddDuck.name();
	redheaddDuck.display();
	redheaddDuck.swim();
	redheaddDuck.fly();
	redheaddDuck.quack();
	cout<<endl;

	RabbardDuck rabbardDuck;
	rabbardDuck.name();
	rabbardDuck.display();
	rabbardDuck.swim();
	rabbardDuck.fly();
	rabbardDuck.quack();
	cout<<endl;

	cout<<" Program to implement Duck Simulation App"<<endl;

	return 0;
}
