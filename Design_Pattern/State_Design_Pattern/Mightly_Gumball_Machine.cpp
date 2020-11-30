#include<stdio.h>
#include<iostream>

using namespace std;

class State {
	public:
		virtual void addmachine(GumballMachine* gumballMachine) =0;
		virtual void insertQuarter() =0;
		virtual void ejectQuarter() =0;
		virtual void turnCrank() =0;
		virtual void dispense() =0;
};

class GumballMachine {
	public:
		State* soldOutState;
		State* noQuarterState;
		State* hasQuarterState;
		State* soldState;
		State* state;
		int count =0;

		void initialize(int numberGumballs)
		{
			SoldState soldStateNew;
			NoQuarterState noQuarterStateNew;
			HasQuarterState hasQuarterStateNew;
			SoldOutState soldOutStateNew;

			soldState = &soldStateNew;
			noQuarterState = &noQuarterStateNew;
			hasQuarterState = &hasQuarterStateNew;
			soldOutState = &soldOutStateNew;

			state = &soldStateNew;
			count = numberGumballs;
			noQuarterState->addmachine(this);
		}
		void setState(State* new_state)
		{
			this->state = new_state;
		}
		State* getSoldState()
		{
			return soldState;
		}
		State* getSoldOutState()
		{
			return soldOutState;
		}
		State* getNoQuarterState()
		{
			return noQuarterState;
		}
		State* getHasQuarterState()
		{
			return hasQuarterState;
		}
		void releaseBall()
		{
			count--;
		}
		int getCount()
		{
			return count;
		}

};

class HasQuarterState : public State {
	GumballMachine gumballMachine;
	public:
       	void addmachine(GumballMachine gumballMachine) {
		this->gumballMachine = gumballMachine;
	}
	void insertQuarter() {
		cout<<"You can’t insert another quarter"<<endl;
	}
	void ejectQuarter() {
		cout<<"Quarter returned"<<endl;
		gumballMachine.setState(gumballMachine.getNoQuarterState());
	}
	void turnCrank() {
		cout<<"You turned..."<<endl;
		gumballMachine.setState(gumballMachine.getSoldState());
	}
	void dispense() {
		cout<<"No gumball dispensed"<<endl;
	}
};


class NoQuarterState : public State {
	GumballMachine gumballMachine;
	public:
       	void addmachine(GumballMachine gumballMachine) {
		this->gumballMachine = gumballMachine;
	}
	void insertQuarter() {
		cout<<"You inserted a quarter"<<endl;
		gumballMachine.setState(gumballMachine.getHasQuarterState());
	}
	void ejectQuarter() {
		cout<<"You haven’t inserted a quarter"<<endl;
	}
	void turnCrank() {
		cout<<"You turned, but there’s no quarter"<<endl;
	}
	void dispense() {
		cout<<"You need to pay first"<<endl;
	}
};

class SoldState : public State {
	GumballMachine gumballMachine;
	public:
       	void addmachine(GumballMachine gumballMachine) {
		this->gumballMachine = gumballMachine;
	}
	void insertQuarter() {
		cout<<"Please wait, we’re already giving you a gumball"<<endl;
	}
	void ejectQuarter() {
		cout<<"Sorry, you already turned the crank"<<endl;
	}
	void turnCrank() {
		cout<<"Turning twice doesn’t get you another gumball!"<<endl;
	}
	void dispense() {
		gumballMachine.releaseBall();
		if (gumballMachine.getCount() > 0) {
			gumballMachine.setState(gumballMachine.getNoQuarterState());
		} else {
			cout<<"Oops, out of gumballs!"<<endl;
			gumballMachine.setState(gumballMachine.getSoldOutState());
		}
	}
};
class SoldOutState : public State {
	GumballMachine gumballMachine;
	public:
       	void addmachine(GumballMachine gumballMachine) {
		this->gumballMachine = gumballMachine;
	}
	void insertQuarter() {
		cout<<"You can’t insert a quarter, the machine is sold out"<<endl;
	}
	void ejectQuarter() {
		cout<<"You can’t eject, you haven’t inserted a quarter yet"<<endl;
	}
	void turnCrank() {
		cout<<"You turned, but there are no gumballs"<<endl;
	}
	void dispense() {
		cout<<"No gumball dispensed"<<endl;
	}
};



int main(void)
{
	cout<<endl<<"Program to implement State Design Pattern "<<endl;

	return 0;
}
