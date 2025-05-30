#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stud_struct.h"

void del_use_roll(ST**ptr,int roll)
{
	enq_delrollnums(roll);
	ST*prev=NULL;
	ST*current=*ptr;
	if((current!=NULL)&&(current->roll==roll))
	{
		*ptr=current->next;
		free(current);
		puts("Deleted record successfully.");
		return;
	}
	while((current!=NULL)&&(current->roll!=roll))
	{
		prev=current;
		current=current->next;
	}
	if(current==NULL)
	{
		puts("No record found for this roll number.");
		return;
	}
	prev->next=current->next;
	free(current);
	puts("Deleted record successfully.");
}

int num_rec_use_name(ST*ptr,char *name)
{
	int num_rec=0;
	while(ptr!=0)
	{
		if(strcmp(ptr->name,name)==0)
		{
			num_rec++;       
		}
		ptr=ptr->next;
	}
	return num_rec;
}

void disp_and_del_rec_use_name(ST**ptr,char*name,int num_rec)
{
	int delroll;
	int rec_arrind = 0;
	ST*current=*ptr;
	puts(" ________________________________________________________________ ");
	puts("|                 |                            |                 |");
	puts("|   Roll Number   |           Name             |    Percentage   |");
	puts("|_________________|____________________________|_________________|");
	puts("|                 |                            |                 |");
	int rec_arr[num_rec];
	while(current!=NULL)
	{
		if(strcmp(current->name,name)==0)
		{
			rec_arr[rec_arrind++]=current->roll;
			printf("|%17d|%28s|%17.1f|\n",current->roll,current->name,current->percentage);
			puts("|_________________|____________________________|_________________|");

		}
		current=current->next;
	}

	while(1)
	{
		printf("Enter the roll number to delete particular record: ");
		scanf("%d",&delroll);
		for(int i=0;i<num_rec;i++)
		{
			if(rec_arr[i]==delroll)
			{
				del_use_roll(ptr,delroll);
				return;
			}
		}
		puts("Please enter a valid roll number.");
	}

}

void del_use_name(ST**ptr,char *name)
{
	int num_rec = num_rec_use_name(*ptr,name);

	if(num_rec>1)
	{
		disp_and_del_rec_use_name(ptr,name,num_rec);
		return;
	}
	else
	{
		ST*prev=NULL;
		ST*current=*ptr;

		if((current!=NULL)&&(strcmp(current->name,name)==0))
		{
			enq_delrollnums(current->roll);
			*ptr=current->next;
			free(current);
			puts("Deleted record successfully.");
			return;
		}
		while((current!=NULL)&&(strcmp(current->name,name)!=0))
		{       
			prev=current;
			current=current->next;
		}
		if(current==NULL)
		{
			puts("No record found on this name.");
			return;
		}
		enq_delrollnums(current->roll);
		prev->next=current->next;
		free(current);
		puts("Deleted record successfully.");
	}
}

void stud_del(ST**ptr)
{
	char op;
	int delroll;
	char delname[40];
	puts(" _________________________________ ");
	puts("|                                 |");
	puts("| r/R : enter roll to del         |");
	puts("| n/N : enter name to del         |");
	puts("|                                 |");
	puts("|_________________________________|");
	printf("\n\n\n");
	do
	{
		printf("Enter your choice : ");
		scanf(" %c",&op);
		while(getchar() != '\n');
		switch(op)
		{
			case 'r':
			case 'R':{
					 printf("Enter the roll number to delete : ");
					 scanf("%d",&delroll);
					 del_use_roll(ptr,delroll);
					 break;
				 }
			case 'n':
			case 'N':{
					 printf("Enter the name to delete: ");
					 scanf("%s",delname);
					 del_use_name(ptr,delname);
					 break;
				 }
			default:{
					puts("Invalid option. Please enter valid option.\n");
					break;
				}

		}
	}while(!((op=='r' || op=='R' || op == 'n' || op == 'N')));

}
