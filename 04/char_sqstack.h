#define MAX_SIZE 100
#define OVERFLOW 0
#define ERROR 0
#define OK 1
using namespace std;
typedef int Status;
typedef struct{//创建字符栈
    char *base;
    char *top;
    int stacksize;
}charSqStack;

Status InitStack(charSqStack &S){//初始化栈
    S.base=new char [MAX_SIZE];
    if(!S.base)exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=MAX_SIZE;
    return OK;
}
Status Push(charSqStack &S,char e){//进行压栈
    if(S.top-S.base==S.stacksize)return ERROR;
    *S.top++=e;
    return OK;
}
Status Pop(charSqStack &S,char &e){//将栈顶元素弹出
    if(S.top==S.base)return ERROR;
    e=*--S.top;
    return OK;
}
char GetTop(charSqStack S){//取得栈顶元素
    if(S.top!=S.base){
        return *(S.top-1);
    }else{
        return ERROR;
    }
}