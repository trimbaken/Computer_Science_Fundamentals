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

class DontFly : public Flyable {
	public:
		void fly() {
			cout<<"Don't Fly"<<endl;
		}
};

class ShortFly : public Flyable {
	public:
		void fly() {
			cout<<"Fly for short duration"<<endl;
		}
};

class LongFly : public Flyable {
	public:
		void fly() {
			cout<<"Fly for long duration"<<endl;
		}
};


class Quackable {
	public:
		virtual void quack() =0;
};

class Quack : public Quackable {
	public:
		void quack()
		{
			cout<<"Duck Quack "<<endl;
		}
};

class DontQuck : public Quackable {
	public:
		void quack()
		{
			cout<<"Duck Don't Quack "<<endl;
		}
};



class MallardDuck : public Duck {
	private:
		Flyable *flyable;
		Quackable *quackable;
	public:
		void name()
		{
			cout<<"Duck Name : Mallard Duck"<<endl;
		}

		void set_flying_behaviour(Flyable *flyable_behaviour)
		{
			this->flyable = flyable_behaviour;
		}

		void fly()
		{
			flyable->fly();
		}
		void set_quackabke_behaviour(Quackable *quackable_behaviour)
		{
			this->quackable = quackable_behaviour;
		}
		void quack()
		{
			quackable->quack();
		}
};

class RedheaddDuck : public Duck, Flyable, Quackable {
	private:
		Flyable *flyable;
		Quackable *quackable;
	public:
		void name()
		{
			cout<<"Duck Name : Redhead Duck"<<endl;
		}
		void set_flying_behaviour(Flyable *flyable_behaviour)
		{
			this->flyable = flyable_behaviour;
		}
		void fly()
		{
			flyable->fly();
		}
		void set_quackabke_behaviour(Quackable *quackable_behaviour)
		{
			this->quackable = quackable_behaviour;
		}
		void quack()
		{
			quackable->quack();
		}
};

class RabbardDuck : public Duck {
	private:
		Flyable *flyable;
		Quackable *quackable;
	public:
		void name()
		{
			cout<<"Duck Name : Rabbar Duck"<<endl;
		}
		void set_flying_behaviour(Flyable *flyable_behaviour)
		{
			this->flyable = flyable_behaviour;
		}
		void fly()
		{
			flyable->fly();
		}
		void set_quackabke_behaviour(Quackable *quackable_behaviour)
		{
			this->quackable = quackable_behaviour;
		}
		void quack()
		{
			quackable->quack();
		}
};


int main(void)
{
	Duck duck;
	duck.display();
	cout<<endl;

	MallardDuck mallardDuck;
	ShortFly shortFly;
	mallardDuck.set_flying_behaviour(&shortFly);
	Quack quack;
	mallardDuck.set_quackabke_behaviour(&quack);
	mallardDuck.name();
	mallardDuck.display();
	mallardDuck.swim();
	mallardDuck.fly();
	mallardDuck.quack();
	cout<<endl;

	RedheaddDuck redheaddDuck;
	LongFly longFLy;
	redheaddDuck.set_flying_behaviour(&longFLy);
	redheaddDuck.set_quackabke_behaviour(&quack);
	redheaddDuck.name();
	redheaddDuck.display();
	redheaddDuck.swim();
	redheaddDuck.fly();
	redheaddDuck.quack();
	cout<<endl;

	RabbardDuck rabbardDuck;
	DontFly dontFly;
	rabbardDuck.set_flying_behaviour(&dontFly);
	DontQuck dont_quack;
	rabbardDuck.set_quackabke_behaviour(&dont_quack);
	rabbardDuck.name();
	rabbardDuck.display();
	rabbardDuck.swim();
	rabbardDuck.fly();
	rabbardDuck.quack();
	cout<<endl;

	cout<<" Program to implement Duck Simulation App"<<endl;

	return 0;
}
