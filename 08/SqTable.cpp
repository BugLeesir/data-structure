#ifndef SqTable_CPP
#define SqTable_CPP
#include"SqTable.h"

#endif
 int select_mov=0,select_swap=0;
 int insert_mov=0,insert_swap=0;
 int quick_mov=0,quick_swap=0;
 int shell_mov=0,shell_swap=0;

void CreatSqTable(SqTable &S){//初始化顺序表
    S.length=0;
}

void RandomTable(SqTable &S){//为顺序表赋予随机值
    S.length=Max_Length;
    srand(time(0));
    for(int i=0;i<Max_Length;++i){
        S.Table[i]=rand()%Max_Length;
    }
}

void PrintSqTable(SqTable S){//打印表中的所有数据
    for(int i=0;i<S.length;++i){
        std::cout<<S.Table[i]<<' ';
    }
    std::cout<<std::endl;
}