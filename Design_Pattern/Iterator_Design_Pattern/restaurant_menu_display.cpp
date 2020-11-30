#include<stdio.h>
#include<iostream>
#include<string.h>
#include <list>

using namespace std;

class MenuItem  {
	public:
		char name[100];
		char description[100];
		int vegiterian;
		int price;

		void create_menu(char new_name[100], char new_description[100], int new_vegiterian, int new_price)
		{
			strcpy(name, new_name);
			strcpy(description, new_description);
			vegiterian = new_vegiterian;
			price = new_price;
		}
		void get_name()
		{
			cout<<"Menu Name : "<<name<<endl;
		}
		void get_description()
		{
			cout<<"Menu Description : "<<description<<endl;
		}
		void get_vegiterian()
		{
			cout<<"Menu Vegiterian : "<<vegiterian<<endl;
		}
		void get_price()
		{
			cout<<"Menu Price : "<<price<<endl;
		}
};

class PancakeHouseMenu {
	public:
		list<MenuItem>menuItems;
		void initialize()
		{
			addItem("K&B’s Pancake Breakfast","Pancnkes with scrambled eggs, and toast",1,3);
			addItem("egular Pancake Breakfast","Pancakes with fried eggs, sausage, and toast",0,4);
		}
		void addItem(char new_name[100], char new_description[100], int new_vegiterian, int new_price)
		{
			MenuItem item;
			item.create_menu(new_name, new_description, new_vegiterian, new_price);
			menuItems.push_back(item);
		}
		list<MenuItem> getMenuItems()
		{
			return menuItems;
		}
};

class DinerMenu {
	public:
		MenuItem menuItems[10];
		int count;
		void initialize()
		{
			count =0;
			addItem("K&B’s Pancake Breakfast","Pancnkes with scrambled eggs, and toast",1,3);
			addItem("egular Pancake Breakfast","Pancakes with fried eggs, sausage, and toast",0,4);
		}
		void addItem(char new_name[100], char new_description[100], int new_vegiterian, int new_price)
		{
			MenuItem item;
			item.create_menu(new_name, new_description, new_vegiterian, new_price);
			menuItems[count++] = item;
		}
		MenuItem* getMenuItems()
		{
			return &menuItems[0];
		}
};


int main(void)
{
	MenuItem menuItem;
	menuItem.create_menu("K&B’s Pancake Breakfast", "Pancakes with scrambled eggs, and toast", 1, 3);
	menuItem.get_name();
	menuItem.get_description();
	menuItem.get_vegiterian();
	menuItem.get_price();
	PancakeHouseMenu pancakeHouseMenu;
	pancakeHouseMenu.initialize();
	list<MenuItem>menuItems = pancakeHouseMenu.getMenuItems();
	MenuItem tempItem = menuItems.front();
	tempItem.get_name();

	DinerMenu dinerMenu;
	dinerMenu.initialize();
	MenuItem* diner_list = dinerMenu.getMenuItems();
	diner_list[1].get_name();
	cout<<"Program to implement Iterator Design Pattern "<<endl;
	return 0;
}
