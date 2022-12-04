#include <iostream>
#include <iterator>
#include <string>
#define ERROR 0
using namespace std;
template <typename T>
struct StackNode{
    T data;
    StackNode<T> *next;
};
template <typename T>
using Stack = StackNode <T> *;

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
template<typename T>
void InitStack(Stack<T> &S){
    S=nullptr;
}

template<typename T>
void Push(Stack<T> &S,T e){
    StackNode<T> *p=new StackNode<T> ;
    p->data=e;
    p->next=S;
    S=p;
}

template <typename T>
void Pop(Stack<T>S,T &e){
    if(S==nullptr)return ;
    e=S->data;
    Stack<T> p=S;
    S=S->next;
    delete p;
}

char GetTop(Stack<char> S){
    if(S==nullptr)return '0';
    else{
        return S->data;
    }
}

template<typename V>
void CreateExpTree(BiTree<V> &T,BiTree<V> lchild,BiTree<V> rchild,V data){
  T= new BiNode<V>;
  T->data=data;
  T->lchild=lchild;
  T->rchild=rchild;
}

bool In(char ch) {  //判断传入的是否是运算符
  char operators[7] = {'+', '-', '*', '/', '(', ')', '#'};
  for (int i = 0; i < 7; ++i) {
    if (operators[i] == ch) {
      return true;
    }
  }
  return false;
}

char Precede(char optr, char ch) {  //判断栈顶运算符与字符串中运算符的优先级
  switch (optr) {
    case '+':
    case '-':
      if (ch == '*' || ch == '/' || ch == '(')
        return '<';
      else
        return '>';
      break;
    case '*':
    case '/':
      if (ch == '(')
        return '<';
      else
        return '>';
      break;
    case '(':
      if (ch == ')')
        return '=';
      else
        return '<';
      break;
    case ')':
      return '>';
      break;
    case '#':
      if (ch == '#')
        return '=';
      else
        return '<';
      break;
    default:
      exit(ERROR);
      break;
  }
}

float GetValue(string data, float a, float b) {
  char option = *data.begin();
  switch (option) {
    case '+':
      return a + b;
      break;
    case '-':
      return a - b;
      break;
    case '*':
      return a * b;
      break;
    case '/':
      if (!b) exit(ERROR);
      return a / b;
      break;
    default:
      cout << "运算符错误" << endl;
      exit(ERROR);
      break;
  }
}

float EvaluateExpTree(BiTree<string> T) {
  float lvalue = 0;
  float rvalue = 0;
  if (T->lchild == nullptr && T->rchild == nullptr)
    return stof(T->data);
  else {
    lvalue = EvaluateExpTree(T->lchild);
    rvalue = EvaluateExpTree(T->rchild);
    return GetValue(T->data, lvalue, rvalue);
  }
}

void InitExpTree(BiTree<string>& T) {
  string expression;
  string temp_str;
  Stack<BiTree<string>> expt;
  Stack<char> optr;
  BiTree<string> a = nullptr;
  BiTree<string> b = nullptr;
  char theta, kh;
  InitStack(expt);
  InitStack(optr);
  Push(optr, '#');
  cin >> expression;
  auto it = expression.begin();
  while (((*it) != '#' )|| (GetTop(optr) != '#')) {
    if (!In(*it)) {
      while (!In(*it)) {
        temp_str += *it;
        ++it;  //迭代器向后移动
      }
      a = nullptr;
      b = nullptr;
      CreateExpTree(T, a, b, temp_str);
      temp_str = "";
    } else {
      switch (Precede(GetTop(optr), *it)) {
        case '<':
          Push(optr, *it);
          ++it;
          break;
        case '>':
          Pop(optr, theta);
          Pop(expt, b);
          Pop(expt, a);
          temp_str = theta;
          CreateExpTree(T, a, b, temp_str);
          temp_str = "";
          Push(expt, T);
          break;
        case '=':
          Pop(optr, kh);
          ++it;
          break;
        default:
          exit(ERROR);
          break;
      }
    }
  }
}

int main() {
  BiTree<string> T;
  InitExpTree(T);
  cout << EvaluateExpTree(T) << endl;
  return 0;
}