#ifndef SqTable_CPP
#define SqTable_CPP
#include"SqTable.h"

#endif
 int select_mov=0,select_swap=0;
 int insert_mov=0,insert_swap=0;
 int quick_mov=0,quick_swap=0;
 int shell_mov=0,shell_swap=0;

void CreatSqTable(SqTable &S){//��ʼ��˳���
    S.length=0;
}

void RandomTable(SqTable &S){//Ϊ˳��������ֵ
    S.length=Max_Length;
    srand(time(0));
    for(int i=0;i<Max_Length;++i){
        S.Table[i]=rand()%Max_Length;
    }
}

void PrintSqTable(SqTable S){//��ӡ���е���������
    for(int i=0;i<S.length;++i){
        std::cout<<S.Table[i]<<' ';
    }
    std::cout<<std::endl;
}