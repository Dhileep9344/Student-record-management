#include<stdio.h>
#include"stud_struct.h"

void stud_show(ST*ptr)
{
	system("clear");
	puts(" ________________________________________________________________ ");
	puts("|                 |                            |                 |");
	puts("|   Roll Number   |           Name             |    Percentage   |");
	puts("|_________________|____________________________|_________________|");
	puts("|                 |                            |                 |");
	if(ptr==0)
	{
		puts("|_________________|____________________________|_________________|");
	}
	while(ptr!=0)
	{
		printf("|%17d|%28s|%17.1f|\n",ptr->roll,ptr->name,ptr->percentage);
		puts("|_________________|____________________________|_________________|");
		ptr=ptr->next;
	}
}
