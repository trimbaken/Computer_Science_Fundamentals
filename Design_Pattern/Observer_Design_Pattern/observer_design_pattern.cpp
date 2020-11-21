#include<stdio.h>
#include<iostream>

using namespace std;

class CurrentCondition {
	private:
		int temperature;
		int humidity;
		int pressure;
	public:
		void set_temperature(int new_temperature)
		{
			temperature = new_temperature;
		}
		void set_humidity(int new_humidity)
		{
			humidity = new_humidity;
		}
		void set_pressure(int new_pressure)
		{
			pressure = new_pressure;
		}
		void display()
		{
			cout<<endl<<"Current Condition:"<<endl;
			cout<<"Temp :"<<temperature<<endl<<"Humidity :"<<humidity<<endl<<"Pressure :"<<pressure<<endl;
		}

};

class WeatherStats {
	private:
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

};


class WeatherData {
	private:
		int temperature;
		int humidity;
		int pressure;
		CurrentCondition current_condition;
		WeatherStats weather_stats;
	public:
		void set_current_codition(CurrentCondition new_current_condition)
		{
			current_condition = new_current_condition;
		}
		void set_weather_stats(WeatherStats new_weather_stats)
		{
			weather_stats = new_weather_stats;
		}
		void set_temperature(int new_temperature)
		{
			temperature = new_temperature;
		}
		void set_humidity(int new_humidity)
		{
			humidity = new_humidity;
		}
		void set_pressure(int new_pressure)
		{
			pressure = new_pressure;
		}
		void display_current_condition()
		{
			current_condition.set_temperature(temperature);
			current_condition.set_humidity(humidity);
			current_condition.set_pressure(pressure);

			current_condition.display();
		}
		void display_weather_stats()
		{
			weather_stats.set_avg_temperature(temperature);
			weather_stats.set_min_temperature(temperature);
			weather_stats.set_max_temperature(temperature);

			weather_stats.display();
		}
};

class WeatherStation {
	private:
		int temperature;
		int humidity;
		int pressure;
		WeatherData weather_data;
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
		void set_weather_data(WeatherData new_weather_data)
		{
			weather_data = new_weather_data;
		}
		void push_weather_data()
		{
			weather_data.set_temperature(temperature);
			weather_data.set_humidity(humidity);
			weather_data.set_pressure(pressure);
			weather_data.display_weather_stats();
			weather_data.display_current_condition();
		}
};

WeatherStation weather_station;


int main(void)
{

	weather_station.set_temperature(43);
	weather_station.set_humidity(50);
	weather_station.set_pressure(60);

	WeatherData weather_data;


	CurrentCondition current_condition;
	weather_data.set_current_codition(current_condition);

	WeatherStats weather_stats;
	weather_data.set_weather_stats(weather_stats);

	weather_station.set_weather_data(weather_data);
	weather_station.push_weather_data();

	cout<<"Program to implement Observer Design Pattern"<<endl;
	return 0;
}
