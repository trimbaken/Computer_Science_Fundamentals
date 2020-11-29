#include<stdio.h>
#include<iostream>

using namespace std;

class Command {
	public:
		virtual void execute()=0;
};

class Light {
	public:
		void on()
		{
			cout<<"Light On "<<endl;
		}
		void off()
		{
			cout<<"Light Off "<<endl;
		}
};

class Fan {
	public:
		void on()
		{
			cout<<"Fan On "<<endl;
		}
		void off()
		{
			cout<<"fan Off "<<endl;
		}
		void decrease_speed()
		{
			cout<<"Decrease Fan Speed "<<endl;
		}
		void increase_speed()
		{
			cout<<"Increase Fan Speed "<<endl;
		}

};

class LightOnCommand : public Command {
	public:
		Light light;
		void set_light(Light light)
		{
			this->light = light;
		}
		void execute()
		{
			light.on();
		}
};

class LightOffCommand : public Command {
	public:
		Light light;
		void set_light(Light light)
		{
			this->light = light;
		}
		void execute()
		{
			light.off();
		}
};

class FanOnCommand : public Command {
	public:
		Fan fan;
		void set_fan(Fan fan)
		{
			this->fan = fan;
		}
		void execute()
		{
			fan.on();
		}
};

class FanOffCommand : public Command {
	public:
		Fan fan;
		void set_fan(Fan fan)
		{
			this->fan = fan;
		}
		void execute()
		{
			fan.off();
		}
};

class FanDecreaseSpeedCommand : public Command {
	public:
		Fan fan;
		void set_fan(Fan fan)
		{
			this->fan = fan;
		}
		void execute()
		{
			fan.decrease_speed();
		}
};

class FanIncreaseSpeedCommand : public Command {
	public:
		Fan fan;
		void set_fan(Fan fan)
		{
			this->fan = fan;
		}
		void execute()
		{
			fan.increase_speed();
		}
};

class RemoteController
{
	public:
		Command* command;
		void set_command(Command* command)
		{
			this->command = command;
		}
		void press_button()
		{
			command->execute();
		}
		void release_button()
		{
			command->execute();
		}
};

int main(void)
{
	Light light;
	LightOnCommand light_on_command;
	light_on_command.set_light(light);
	LightOffCommand light_off_command;
	light_off_command.set_light(light);

	RemoteController remote_controller;
	remote_controller.set_command(&light_on_command);
	remote_controller.press_button();

	remote_controller.set_command(&light_off_command);
	remote_controller.release_button();

	Fan fan;
	FanOnCommand fan_on_command;
	fan_on_command.set_fan(fan);
	FanOffCommand fan_off_command;
	fan_off_command.set_fan(fan);
	FanDecreaseSpeedCommand fan_decrease_speed_command;
	fan_decrease_speed_command.set_fan(fan);
	FanIncreaseSpeedCommand fan_increase_speed_command;
	fan_increase_speed_command.set_fan(fan);

	remote_controller.set_command(&fan_on_command);
	remote_controller.press_button();

	remote_controller.set_command(&fan_off_command);
	remote_controller.release_button();

	remote_controller.set_command(&fan_decrease_speed_command);
	remote_controller.press_button();

	remote_controller.set_command(&fan_increase_speed_command);
	remote_controller.press_button();

	cout<<"Program to implement Command Design Pattern"<<endl;

	return 0;
}
