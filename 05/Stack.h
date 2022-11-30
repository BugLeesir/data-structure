template <typename T>
struct StackNode{
    T data;
    StackNode<T> *next;
};
template <typename T>
using Stack = StackNode <T> *;

template<typename T>
void InitStack(Stack<T> &S){
    S=nullptr;
    return ;
}

template<typename T>
void Push(Stack<T> &S,T e){
    StackNode<T> *p=new StackNode<T> ;
    p->data=e;
    p->next=S;
    S=p;
    return;
}

template <typename T>
void Pop(Stack<T>S,T &e){
    if(S==nullptr)return ;
    e=S->data;
    Stack p=S;
    S=S->next;
    delete p;
    return;
}

template<typename T>
T GetTop(Stack<T> S){
    if(S==nullptr)return 0;
    else return S->data;
}