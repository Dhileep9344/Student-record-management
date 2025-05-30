#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"stud_struct.h"

int rollgen = 1;
ST* hptr = NULL;
DLR* dhptr = NULL;

int main()
{
	system("clear");
	char op;
	while(1)
	{
		puts(" ________________________________________________ ");
		puts("|                                                |");
		puts("|          *****STUDENT RECORD MENU*****         |");
		puts("| ______________________________________________ |");
		puts("|                                                |");
		puts("| a/A  : add new record                          |");
		puts("| d/D  : delete a record                         |");
		puts("| s/S  : show the list                           |");
		puts("| m/M  : modify a record                         |");
		puts("| v/V  : save                                    |");
		puts("| e/E  : exit                                    |");
		puts("| t/T  : sort the list                           |");
		puts("| l/L  : delete all the record                   |");
		puts("| r/R  : reverse the list                        |");
		puts("|                                                |");
		puts("|________________________________________________|");
		printf("\n\n");
		do{
			printf("Enter your choice: ");
			scanf(" %c",&op);
			while(getchar()!='\n');
			if(!((op=='a' || op=='A' || op == 'd' || op == 'D' || op=='s' || op=='S' || op == 'm' || op == 'M' || op=='v' || op=='V' || op == 'e' || op == 'E' || op=='t' || op=='T' || op == 'l' || op == 'L' || op=='r' || op=='R')))
			{
				puts("Invalid option.Please enter valid option.");
			}
			printf("\n");
		}while(!((op=='a' || op=='A' || op == 'd' || op == 'D' || op=='s' || op=='S' || op == 'm' || op == 'M' || op=='v' || op=='V' || op == 'e' || op == 'E' || op=='t' || op=='T' || op == 'l' || op == 'L' || op=='r' || op=='R')));

		switch(op)
		{
			case 'a':
			case 'A':{
					 stud_add(&hptr);
					 break;
				 }
			case 'd':
			case 'D':{
					 stud_del(&hptr);
					 break;
				 }
			case 's':
			case 'S':{
					 stud_show(hptr);
					 break;
				 }
			case 'm':
			case 'M':{
					 stud_mod(hptr);
					 break;
				 }
			case 'v':
			case 'V':{
					 stud_save(hptr);
					 break;
				 }
			case 'e':
			case 'E':{
					 char op;
					 puts(" _________________________________ ");
					 puts("|                                 |");
					 puts("| s/S : save and exit             |");
					 puts("| e/E : exit without saving       |");
					 puts("|                                 |");
					 puts("|_________________________________|");
					 printf("\n\n");
					 do{

						 printf("Enter your choice : ");
						 scanf(" %c",&op);
						 while(getchar()!='\n');
						 if(!((op=='e' || op=='E')||(op == 's' || op == 'S')))
							 puts("Invalid Option.Please Enter Valid Option.\n");
						 if(op=='e' || op=='E')
							 return 0;
						 else if(op == 's' || op == 'S')
						 {
							 stud_save(hptr);
							 return 0;
						 }
					 }while(!((op=='e' || op=='E')||(op == 's' || op == 'S')));
					 break;

				 }
			case 't':
			case 'T':{
					 stud_sort(&hptr);
					 break;
				 }
			case 'l':
			case 'L':{
					 stud_delall(&hptr);
					 break;
				 }
			case 'r':
			case 'R':{
					 stud_reverse(&hptr);
					 break;
				 }


			default:{
					break;
				}
		}
	}
}
