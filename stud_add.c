#include<stdio.h>
#include<stdlib.h>
#include"stud_struct.h"

void stud_add_middle(ST**ptr,int roll)
{
	ST*temp = (ST*)malloc(sizeof(ST));
	temp->roll=roll;
	printf("\nEnter the name : ");
        scanf("%s",temp->name);
        printf("\nEnter the percentage : ");
        scanf("%f",&temp->percentage);
        while((temp->percentage<0)||(temp->percentage>100))
        {
                puts("Please enter the correct percentage (Min:0 Max:100).");
                printf("\nEnter the percentage: ");
                scanf("%f",&temp->percentage);
        }

	if(*ptr==NULL || (((*ptr)->roll)>roll))
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		ST*prev=NULL;
		ST*current=*ptr;
                while((current!=NULL)&&(current->roll)<roll)
                {
			prev=current;
			current=current->next;
                }
		prev->next=temp;
                temp->next = current;
	}
	puts("Record created successfully.");

}

void stud_add(ST**ptr)
{
	ST*temp =(ST*)malloc(sizeof(ST));
	int delrolls = delrollscount();
	if(delrolls==0)
		temp->roll=rollgen++;
	else
	{
		temp->roll=delrollgen();
		stud_add_middle(ptr,temp->roll);
		return;
	}
	printf("\nEnter the name : ");
	scanf("%s",temp->name);
	printf("\nEnter the percentage : ");
	scanf("%f",&temp->percentage);
	while((temp->percentage<0)||(temp->percentage>100))
	{
		puts("Please enter the correct percentage (Min:0 Max:100).");
		printf("\nEnter the percentage: ");
		scanf("%f",&temp->percentage);
	}


	if(*ptr==NULL)
	{
		temp->next = *ptr;
		*ptr=temp;
		puts("\nRecord created successfully.");
	}
	else
	{
		ST*last=*ptr;
		while(last->next!=0)
		{
			last=last->next;
		}
		temp->next = last->next;
		last->next = temp;
		puts("\nRecord created successfully.");
	}
}

int node_count(ST*ptr)
{
        int count=0;
        if(ptr==0)
                return 0;
        while(ptr!=0)
        {
                count++;
                ptr=ptr->next;
        }
        return count;
}

int delrollscount()
{
        int count=0;
        DLR*temp = dhptr;
        while(temp!=0)
        {
                count++;
                temp=temp->next;
        }
        return count;
}

void enq_delrollnums(int roll)
{
        DLR* temp = (DLR*)malloc(sizeof(DLR));
        DLR*current=dhptr;
        if(dhptr==NULL)
        {
                temp->next = dhptr;
                temp->roll=roll;
                dhptr=temp;
        }

        else
        {
                while(current->next!=NULL)
                {
                        current=current->next;
                }
                temp->next=current->next;
                temp->roll = roll;
                current->next=temp;
        }

}

void deq_delrollnums()
{
        if(dhptr!=NULL)
        {
                DLR*temp = dhptr;
                dhptr = dhptr->next;
                free(temp);
        }
}

int delrollgen()
{
        int roll = dhptr->roll;
        deq_delrollnums();
        return roll;
}


