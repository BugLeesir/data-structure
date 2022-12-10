#ifndef SqTable_H
#define SqTable_H
#define Max_Length 100
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<iostream>


struct SqTable{
    int Table[Max_Length];
    int length;
};//存放数据的顺序表


extern int select_mov,select_swap;//用于记录比较和交换次数
extern int insert_mov,insert_swap;
extern int quick_mov,quick_swap;
extern int shell_mov,shell_swap;

void CreatSqTable(SqTable &);

void RandomTable(SqTable &);

void PrintSqTable(SqTable);

#endif