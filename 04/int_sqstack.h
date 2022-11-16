#define MAX_SIZE 100
#define OVERFLOW 0
#define ERROR 0
#define OK 1
using namespace std;
typedef int Status;
typedef struct{//´´½¨Êý×ÖÕ»
    int *base;
    int *top;
    int stacksize;
}intSqStack;

Status InitStack(intSqStack &S){
    S.base=new int [MAX_SIZE];
    if(!S.base)exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=MAX_SIZE;
    return OK;
}
Status Push(intSqStack &S,int e){
    if(S.top-S.base==S.stacksize)return ERROR;
    *S.top++=e;
    return OK;
}
Status Pop(intSqStack &S,int &e){
    if(S.top==S.base)return ERROR;
    e=*--S.top;
    return OK;
}
int GetTop(intSqStack S){
    if(S.top!=S.base){
        return *(S.top-1);
    }else{
        return ERROR;
    }
}