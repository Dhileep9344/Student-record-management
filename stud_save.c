#include<stdio.h>
#include"stud_struct.h"

void stud_save(ST*ptr)
{
	FILE* fp=fopen("studentrecords.dat","w");
	fprintf(fp," ________________________________________________________________ \n");
	fprintf(fp,"|                 |                            |                 |\n");
	fprintf(fp,"|   Roll Number   |           Name             |    Percentage   |\n");
	fprintf(fp,"|_________________|____________________________|_________________|\n");
	fprintf(fp,"|                 |                            |                 |\n");
	while(ptr!=0)
	{
		fprintf(fp,"|%17d|%28s|%17.1f|\n",ptr->roll,ptr->name,ptr->percentage);
		fprintf(fp,"|_________________|____________________________|_________________|\n");
		ptr=ptr->next;
	}
}
