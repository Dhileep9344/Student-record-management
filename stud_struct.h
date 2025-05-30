#include"stdio.h"
#include"stdlib.h"
#ifndef STUD_STRUCT_H
#define STUD_STRUCT_H

typedef struct student
{
        int roll;
        char name[40];
        float percentage;
        struct student* next;
}ST;

typedef struct delroll
{
        int roll;
        struct delroll*next;
}DLR;


extern int node_count();
extern int delrollscount();
extern void enq_delrollnums();
extern void deq_delrollnums();
extern int delrollgen();

void stud_add(ST**);
void stud_del(ST**);
void stud_mod(ST*);
void stud_show(ST*);
void stud_save(ST*);
void stud_reverse(ST**);
void stud_sort(ST**);
void stud_delall(ST**);

extern int rollgen;
extern ST* hptr;
extern DLR* dhptr;

#endif
