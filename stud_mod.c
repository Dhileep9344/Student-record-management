#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stud_struct.h"

void modify_data(ST*ptr)
{
	char op;
	puts(" _______________________________________________________ ");
	puts("|                                                       |");
	puts("| Enter what do you want to modify                      |");
	puts("|                                                       |");
	puts("| n/N : name                                            |");
	puts("| p/P : percentage                                      |");
	puts("|                                                       |");
	puts("|_______________________________________________________|");
	printf("\n\n\n");
	do{
		printf("Enter your choice : ");
		scanf(" %c",&op);
		while(getchar()!='\n');
		switch(op)
		{
			case 'n':
			case 'N':{
					 printf("Enter the name to be modified : ");
					 scanf("%s",ptr->name);
					 return;
				 }
			case 'p':
			case 'P':{
					 printf("Enter the percentage to be modified : ");
					 scanf("%f",&(ptr->percentage));
					 return;
				 }
			default:{
					puts("Invalid Option.Please Enter valid option.");
					break;
				}
		}
	}while(!((op=='n' || op=='N')||(op == 'p' || op == 'P')));
}

void mod_use_roll(ST*ptr,int roll)
{
	ST*temp=ptr;
	while(temp!=NULL)
	{
		if((temp->roll)==roll)
		{
			modify_data(temp);
			return;
		}
		temp = temp->next;
	}
	if(temp==NULL)
	{
		printf("No record found on this roll number.\n\n");
		return;
	}
}

void mod_use_name(ST*ptr,char *name,int roll)
{
	ST*temp=ptr;
	while(temp!=NULL)
	{
		if(((strcmp(temp->name,name))==0)&&((temp->roll) == roll))
		{
			modify_data(temp);
			return;
		}
		temp= temp->next;
	}

	if(temp==NULL)
	{
		printf("No record found on this name with this roll number.\n\n");
		return;
	}
}

void mod_use_per(ST*ptr,float per,int roll)
{
	ST*temp=ptr;
	while(temp!=NULL)
	{
		if(((temp->percentage)==per)&&((temp->roll)==roll))
		{
			modify_data(temp);
			return;
		}
		temp= temp->next;
	}

	if(temp==NULL)
	{
		printf("No record found on this name with this roll number.\n\n");
		return;
	}
}

void stud_mod(ST*ptr)
{
	char op;
	puts(" _______________________________________________________ ");
	puts("|                                                       |");
	puts("| Enter which record to search for modification         |");
	puts("|                                                       |");
	puts("| r/R : to search a rollno                              |");
	puts("| n/N : to search a name                                |");
	puts("| p/P : percentage based                                |");
	puts("|                                                       |");
	puts("|_______________________________________________________|");
	printf("\n\n\n");
	do
	{
		printf("Enter your choice: ");
		scanf(" %c",&op);
		while(getchar() != '\n');
		switch(op)
		{
			case 'r':
			case 'R':{
					 int roll;
					 printf("\nEnter the roll no: ");
					 scanf("%d",&roll);
					 mod_use_roll(ptr,roll);
					 break;
				 }
			case 'n':
			case 'N':{
					 char name[30];
					 int roll;
					 printf("\nEnter the name: ");
					 scanf("%s",name);
					 printf("\nEnter the roll number of the particular record with this name: ");
					 scanf("%d",&roll);
					 mod_use_name(ptr,name,roll);
					 break;
				 }
			case 'p':
			case 'P':{
					 float per;
					 int roll;
					 printf("\nEnter the percentage: ");
					 scanf("%f",&per);
					 printf("\nEnter the roll number of the particular record with this percentage: ");
					 scanf("%d",&roll);
					 mod_use_per(ptr,per,roll);
					 break;
				 }
			default:{
					puts("Invalid option.Please enter valid option.\n\n");
					break;
				}

		}
	}while(!((op=='r' || op=='R' || op == 'n' || op == 'N' || op == 'p' || op == 'P')));
}
