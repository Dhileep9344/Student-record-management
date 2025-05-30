#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stud_struct.h"

void stud_reverse(ST**ptr)
{
	int nodecount=node_count(*ptr);
	int nodesize = sizeof(ST)-8;
	ST*first = *ptr;
	ST*last = *ptr;
	int i,j,ini,las;
	ST*temp=(ST*)malloc(nodesize);
	for(i=0,j=nodecount-1;i<j;i++,j--)
	{
		for(ini=0;ini<i;ini++)
		{
			first = first->next;
		}
		for(las=0;las<j;las++)
		{
			last=last->next;
		}

		memcpy(temp,first,nodesize);
		memcpy(first,last,nodesize);
		memcpy(last,temp,nodesize);
		first=*ptr;
		last=*ptr;
	}
	free(temp);

}
