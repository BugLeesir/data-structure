#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>

#include "char_sqstack.h"
#include "int_sqstack.h"
#define SUCCESS 0
int Operate(int a, char theta, int b) {  //根据传入的运算符将a,b进行运算
  char option = theta;
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
int EvaluateExpression() {  //构建运算函数
  intSqStack opnd;
  charSqStack optr;
  string expression;
  int a, b;
  char theta, kh;
  InitStack(opnd);
  InitStack(optr);  //将两个栈初始化，分别存放运算符和操作数
  Push(optr, '#');
  cin >> expression;
  auto it = expression.begin();  //用迭代器指向字符串的第一个字符
  while ((*it) != '#' ||
         GetTop(optr) != '#') {  //表达式未查找完毕且optr栈顶元素不空
    if (!In(*it)) {
      int x = 0;
      while (!In(*it)) {
        x = x * 10 + *it - '0';  //将字符转化为数字
        ++it;                    //迭代器向后移动
      }
      Push(opnd, x);
    } else {
      switch (Precede(GetTop(optr), *it)) {  //进行优先级的比较
        case '<':
          Push(optr, *it);
          ++it;
          break;
        case '>':
          Pop(optr, theta);
          Pop(opnd, b);
          Pop(opnd, a);
          Push(opnd, Operate(a, theta, b));  //将运算结果压入opnd栈
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
  return GetTop(opnd);  // opnd栈即为表达式求值结果
}

int main() {
  int result = EvaluateExpression();  //进行运算
  cout << result << endl;
  system("pause");
  return SUCCESS;
}
