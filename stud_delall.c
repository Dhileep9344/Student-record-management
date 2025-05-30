#include"stud_struct.h"

void stud_delall(ST**ptr)
{
	while(*ptr!=NULL)
	{
		ST*temp=*ptr;
		free(temp);
		*ptr=(*ptr)->next;
	}
}
