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
};

class Flyable {
	public:
		virtual void fly() =0;
//		virtual void flyForShotDuration() =0;
};

class Quackable {
	public:
		virtual void quack() =0;
};

class MallardDuck : public Duck, Flyable, Quackable {
	public:
		void name()
		{
			cout<<"Duck Name : Mallard Duck"<<endl;
		}
		void fly()
		{
			cout<<"Mallard Duck Fly in sky"<<endl;
		}
		void quack()
		{
			cout<<"Mallard Duck quack"<<endl;
		}
};

class RedheaddDuck : public Duck, Flyable, Quackable {
	public:
		void name()
		{
			cout<<"Duck Name : Redhead Duck"<<endl;
		}
		void fly()
		{
			cout<<"Redhead Duck Fly in sky"<<endl;
		}
		void quack()
		{
			cout<<"Redhead Duck quack"<<endl;
		}
};

class RabbardDuck : public Duck {
	public:
		void name()
		{
			cout<<"Duck Name : Rabbar Duck"<<endl;
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
	cout<<endl;

	cout<<" Program to implement Duck Simulation App"<<endl;

	return 0;
}
