template<typename T>
struct QNode{
    T data;
    QNode *next;
};
template<typename T>
using QueuePtr = QNode<T>*;
template<typename T>
struct LinkQueue{
    QueuePtr<T> front;
    QueuePtr<T> rear;
};

template<typename T>
void InitQueue(LinkQueue<T> &Q){
    Q.front=Q.rear=new QNode<T>;
    Q.front->next=nullptr;
    return;
}

template<typename T>
void EnQueue (LinkQueue<T> &Q,T e){
    QueuePtr<T> p;
    p=new QNode<T>;
    p->data=e;
    p->next=nullptr;
    Q.rear->next=p;
    Q.rear=p;
    return ;
}

template <typename T>
void DeQueue(LinkQueue<T> &Q,T &e){
    if(Q.front==Q.rear)return ;
    QueuePtr<T> p;
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)Q.rear=Q.front;
    delete p;
    return; 
}
