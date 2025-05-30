#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stud_struct.h"

void sort_name(ST*ptr)
{
	ST*temp=ptr;
	int nodecount=node_count(ptr);
	int nodesize = sizeof(ST)-8;
	ST*temp1=(ST*)(malloc)(nodesize);
	ST*arrptr[nodecount];
	int count=0;
	while(temp!=NULL)
	{
		arrptr[count]=temp;
		temp=temp->next;
		count++;
	}
	int i,j;
	for(i=0;i<nodecount-1;i++)
	{
		for(j=i+1;j<nodecount;j++)
		{
			if(((arrptr[i])->name[0])>((arrptr[j])->name[0]))
			{
				memcpy(temp1,arrptr[i],nodesize);
				memcpy(arrptr[i],arrptr[j],nodesize);
				memcpy(arrptr[j],temp1,nodesize);
			}
		}
	}
	free(temp1);
}

void sort_percentage(ST*ptr)
{
	ST*temp=ptr;
	int nodecount=node_count(ptr);
	int nodesize = sizeof(ST)-8;
	ST*temp1=(ST*)(malloc)(nodesize);
	ST*arrptr[nodecount];
	int count=0;
	while(temp!=NULL)
	{
		arrptr[count]=temp;
		temp=temp->next;
		count++;
	}
	int i,j;
	for(i=0;i<nodecount-1;i++)
	{
		for(j=i+1;j<nodecount;j++)
		{
			if(((arrptr[i])->percentage)>((arrptr[j])->percentage))
			{
				memcpy(temp1,arrptr[i],nodesize);
				memcpy(arrptr[i],arrptr[j],nodesize);
				memcpy(arrptr[j],temp1,nodesize);
			}
		}
	}
	free(temp1);
}

void stud_sort(ST**ptr)
{
	if(*ptr == NULL)
	{
		puts("The record is empty.");
		return;
	}
	if((*ptr!=NULL) && ((*ptr)->next == NULL))
	{
		puts("Only one record available. Sorting is not possible");
		return;
	}
	char op;
	puts(" _________________________________________ ");
	puts("|                                         |");
	puts("| Enter                                   |");
	puts("|                                         |");
	puts("| n/N : sort with name                    |");
	puts("| p/P : sort with percentage              |");
	puts("|_________________________________________|");
	printf("\n\n\n");
	do
	{
		printf("Enter your choice : ");
		scanf(" %c",&op);
		while(getchar() != '\n');
		switch(op)
		{
			case 'n':
			case 'N':{
					 sort_name(*ptr);
					 break;
				 }
			case 'p':
			case 'P':{
					 sort_percentage(*ptr);
					 break;
				 }
			default:{
					puts("Invalid Option. Please enter valid option.\n");
					break;
				}
		}
	}while(!((op=='n' || op=='N')||(op == 'p' || op == 'P')));
}
