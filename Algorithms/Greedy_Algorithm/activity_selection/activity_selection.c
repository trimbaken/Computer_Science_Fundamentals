#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_ACTIVITIES 100

typedef struct activity_s
{
	int start_time;
	int finish_time;
	int is_selected;
} activity_t;

activity_t activities[MAX_ACTIVITIES];
int activity_count;

int add_activity(int start_time, int finish_time)
{
	if(activity_count >= MAX_ACTIVITIES)
	{
		printf("\nMemory full \n");
		return 0;
	}
	activities[activity_count].start_time = start_time;
	activities[activity_count].finish_time = finish_time;
	activities[activity_count].is_selected = 0;
	activity_count++;
	return 1;
}

int select_activities()
{
	int current_activity =0;
	int i =0;
	if(activity_count ==0)
	{
		printf("\nNo activity is added\n");
		return 0;
	}
	while(current_activity < activity_count)
	{
		printf("\nSelect activity [%d] start time [%d] finish time [%d]\n", current_activity+1, activities[current_activity].start_time, activities[current_activity].finish_time);
		for(i= current_activity+1; i<activity_count; i++)
		{
			if(activities[i].start_time >= activities[current_activity].finish_time)
			{
				break;
			}
		}
		current_activity = i;
	}
	return 1;
}

int print_all_activities()
{
	int i =0;
	if(activity_count ==0)
	{
		printf("\nNo Activity is added\n");
		return 0;
	}
	printf("\nAll Added Activities:\n");
	for(i=0; i<activity_count; i++)
	{
		printf("Activity [%d] Start time [%d] Finish time [%d]\n", i+1, activities[i].start_time, activities[i].finish_time);
	}
	return 1;
}
void init()
{
	int i =0;
	int operation =0;
	int start_time =0;
	int finish_time =0;
	activity_count =0;
	for(i =0; i<MAX_ACTIVITIES; i++)
	{
		activities[i].start_time = -1;
		activities[i].finish_time = -1;
		activities[i].is_selected = 0;
	}
	while(1)
	{
		printf("\n\nSelect Operation\n");
		printf("1. Add Activity\n");
		printf("2. Activity Selection\n");
		printf("3. Print All Activities\n");
		printf("\n0. Exit\n");
		scanf("%d",&operation);
		if(operation >3)
		{
			system("clear");
			printf("\nInvalid Operation, Please Enter Valide Operation\n");
			continue;
		}
		system("clear");
		switch(operation)
		{
			case 1:
			{
				printf("\nAdd Activity\n");
				printf("\nEnter start time and finish time:\n");
				scanf("%d %d", &start_time, &finish_time);
				if(!add_activity(start_time, finish_time))
				{
					printf("\nFail to add activity\n");
				}
				else
				{
					printf("\nActivity Added\n");
				}
				break;
			}
			case 2:
			{
				printf("\nSelect Activities\n");
				if(!select_activities())
				{
					printf("\nFail to select activities\n");
				}
				break;
			}
			case 3:
			{
				printf("\nPrint All Activities:\n");
				if(!print_all_activities())
				{
					printf("\nFail to print all activities:\n");
				}
				break;
			}
			case 0:
			{
				printf("\nThanks for using our service\n");
				return;
			}
			default :
			{
				printf("\nInvalide Operation\n");
				break;
			}
		}
	}
}

int main(void)
{
	init();
	printf("\nProgram to implement activity selection task:\n");
	return 0;
}
