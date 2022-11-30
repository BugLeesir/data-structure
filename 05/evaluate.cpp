#include <iostream>
#include <iterator>
#include <string>

#include "BiTree.h"
#include "Stack.h"

#define ERROR 0
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

void InitExpTree(BiTree<string>& T) {
  Stack<BiTree<string>> expt;
  Stack<char> optr;
  string expression;
  BiTree<string> a = nullptr;
  BiTree<string> b = nullptr;
  char theta, kh;
  InitStack(expt);
  InitStack(optr);
  Push(optr, '#');
  cin >> expression;
  auto it = expression.begin();
  while ((*it) != '#' || GetTop(optr) != '#') {
    string temp_str;
    if (!In(*it)) {
      while (!In(*it)) {
        temp_str += *it;
        ++it;  //迭代器向后移动
      }
      a = nullptr;
      b = nullptr;
      CreateExpTree(T, a, b, temp_str);
    } else
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

int main() {
  BiTree<string> T;
  InitExpTree(T);
  cout << EvaluateExpTree(T) << endl;
  return 0;
}