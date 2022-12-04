
// #include "Queue.h"
// #include "Stack.h"
using namespace std;

template <typename T>
struct BiNode {
  T data;
  BiNode<T> *rchild, *lchild;
  int ltag,rtag;
};
template <typename T>
using BiTree = BiNode<T> *;
template <typename T>
using BiThrNode=BiNode<T>;
template <typename T>
using BiThrTree = BiThrNode<T> *;
// template <typename V>
// void PreOrderTraverse(BiTree<V> T) {  //先序遍历算法
//   if (T == nullptr)
//     return;
//   else {
//     cout << T->date << ' ';
//     PreOrderTraverse(T->lchild);
//     PreOrderTraverse(T->rchild);
//   }
// }

// template <typename V>
// void InOrderTraverse(BiTree<V> T) {  //中序遍历算法
//   if (T == nullptr)
//     return;
//   else {
//     InOrderTraverse(T->lchild);
//     cout << T->date << ' ';
//     InOrderTraverse(T->rchild);
//   }
// }

// template <typename V>
// void PostOrderTraverse(BiTree<V> T) {  //后序遍历算法
//   if (T == nullptr)
//     return;
//   else {
//     PostOrderTraverse(T->lchild);
//     PostOrderTraverse(T->rchild);
//     cout << T->date << ' ';
//   }
// }

// template <typename V>
// void InOrderTraverseByStack(BiTree<V> T) {
//   BiTree<V> p;
//   Stack<BiNode<V>> S;
//   InitStack(S);
//   p = T;
//   while (p || !S) {  //利用栈进行中序遍历
//     if (p) {
//       Push(S, p);
//       p = p->lchild;
//     } else {
//       BiNode<V> q;
//       Pop(S, q);
//       cout << q.data << ' ';
//       p = q.rchild;
//     }
//   }
// }

// template <typename V>
// void LevelOrder(BiTree<V> T) {  //层次遍历算法
//   BiNode<V> *p;
//   QueuePtr<BiNode<V>> qu;
//   InitQueue(qu);
//   EnQueue(qu, T);
//   while (qu) {
//     DeQueue(qu, p);
//     cout << p->data << " ";
//     if (p->lchild) EnQueue(qu, p->lchild);
//     if (p->rchild) EnQueue(qu, p->rchild);
//   }
// }

// template <typename V>
// void CreatBiTree(BiTree<V> &T) {  //先序遍历建立二叉树
//   char ch;
//   cin >> ch;
//   if (ch == '#')
//     T = nullptr;
//   else {
//     T = new BiNode<V>;
//     T->data = ch;
//     CreatBiTree(T->lchild);
//     CreatBiTree(T->rchild);
//   }
//   return;
// }

// template <typename V>
// void Copy(BiTree<V> T, BiTree<V> NewT) {  //先序遍历复制树
//   if (T == nullptr) {
//     NewT = nullptr;
//     return;
//   } else {
//     NewT = new BiNode<V>;
//     NewT->data = T->data;
//     Copy(T->lchild, NewT->lchild);
//     Copy(T->rchild, NewT->rchild);
//   }
// }

// template <typename V>
// int Depth(BiTree<V> T) {  //计算二叉树的深度
//   int m, n;
//   if (T == nullptr)
//     return 0;
//   else {
//     m = Depth(T->lchild);
//     n = Depth(T->rchild);
//     if (m > n)
//       return (m + 1);
//     else
//       return (n + 1);
//   }
// }

// template <typename V>
// int NodeCount(BiTree<V> T) {//计算二叉树的节点个数
//   if (T == nullptr)
//     return 0;
//   else
//     return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
// }

// template<typename  V>
// int LeadCount(BiTree<V> T){//找到二叉树中叶子节点的个数
//     if(T==nullptr)return 0;
//     if(T->lchild==nullptr&&T->rchild==nullptr)return 1;
//     else return LeadCount(T->lchild)+LeadCount(T->rchild);
// }

template<typename V>
void CreateExpTree(BiTree<V> &T,BiTree<V> lchild,BiTree<V> rchild,V data){
  T= new BiNode<V>;
  T->data=data;
  T->lchild=lchild;
  T->rchild=rchild;
}