#include<stdio.h>
#include<iostream>
#include <list>

using namespace std;

class Observer {
	public:
		virtual void update()=0;
};

class WeatherStation {
	private:
		int temperature;
		int humidity;
		int pressure;
		list<Observer*> observer_list;
		list<Observer*>::iterator it;
	public:
		void set_temperature(int new_temperature)
		{
			temperature = new_temperature;
		}
		int get_temperature()
		{
			return temperature;
		}
		void set_humidity(int new_humidity)
		{
			humidity = new_humidity;
		}
		int get_humidity()
		{
			return humidity;
		}
		void set_pressure(int new_pressure)
		{
			pressure = new_pressure;
		}
		int get_pressure()
		{
			return pressure;
		}
		void add_observer(Observer* new_observer)
		{
			observer_list.insert(observer_list.end(), new_observer);
		}
		void push_weather_data()
		{
			for(it = observer_list.begin(); it != observer_list.end(); it++)
			{
				Observer* temp;
				temp = *it;
				temp->update();
			}
		}
};

WeatherStation weather_station;

class CurrentCondition : public Observer {
	public:
		void update()
		{
			cout<<endl<<"Current Condition:"<<endl;
			cout<<"Temp :"<<weather_station.get_temperature()<<endl<<"Humidity :"<<weather_station.get_humidity()<<endl<<"Pressure :"<<weather_station.get_pressure()<<endl;
		}
};

class WeatherStats : public Observer {
		int avg_temperature;
		int min_temperature;
		int max_temperature;
	public:
		void set_avg_temperature(int new_temperature)
		{
			avg_temperature = new_temperature;
		}
		void set_min_temperature(int new_temperature)
		{
			min_temperature = new_temperature - 10;
		}
		void set_max_temperature(int new_temperature)
		{
			max_temperature = new_temperature + 10;
		}
		void display()
		{
			cout<<endl<<"Weather Stats:"<<endl;
			cout<<"Avg :"<<avg_temperature<<endl<<"Min :"<<min_temperature<<endl<<"Max :"<<max_temperature<<endl;
		}
		void update()
		{
			avg_temperature = weather_station.get_temperature();
			min_temperature = weather_station.get_temperature() - 10;
			max_temperature = weather_station.get_temperature() + 10;

			display();
		}

};

class Forecast : public Observer {
	public:
		void update()
		{
			int temperature = weather_station.get_temperature();
			if(temperature >40) {
				cout<<"Today's Forcast : Dry"<<endl;
			} else {
				cout<<"Today's Forcast : Humid"<<endl;
			}
		}
};

int main(void)
{

	weather_station.set_temperature(43);
	weather_station.set_humidity(50);
	weather_station.set_pressure(60);

	CurrentCondition current_condition;
	WeatherStats weather_stats;

	weather_station.add_observer(&current_condition);
	weather_station.add_observer(&weather_stats);

	weather_station.push_weather_data();

// Add new Display
	Forecast forecast;
	weather_station.add_observer(&forecast);
// Update weather data to all devices
	weather_station.push_weather_data();

	cout<<endl<<"Program to implement Observer Design Pattern"<<endl;
	return 0;
}
