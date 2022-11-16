#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>

#include "char_sqstack.h"
#include "int_sqstack.h"
#define SUCCESS 0
int Operate(int a, char theta, int b) {  //���ݴ�����������a,b��������
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
      cout << "���������" << endl;
      exit(ERROR);
      break;
  }
}
bool In(char ch) {  //�жϴ�����Ƿ��������
  char operators[7] = {'+', '-', '*', '/', '(', ')', '#'};
  for (int i = 0; i < 7; ++i) {
    if (operators[i] == ch) {
      return true;
    }
  }
  return false;
}
char Precede(char optr, char ch) {  //�ж�ջ����������ַ���������������ȼ�
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
int EvaluateExpression() {  //�������㺯��
  intSqStack opnd;
  charSqStack optr;
  string expression;
  int a, b;
  char theta, kh;
  InitStack(opnd);
  InitStack(optr);  //������ջ��ʼ�����ֱ���������Ͳ�����
  Push(optr, '#');
  cin >> expression;
  auto it = expression.begin();  //�õ�����ָ���ַ����ĵ�һ���ַ�
  while ((*it) != '#' ||
         GetTop(optr) != '#') {  //���ʽδ���������optrջ��Ԫ�ز���
    if (!In(*it)) {
      int x = 0;
      while (!In(*it)) {
        x = x * 10 + *it - '0';  //���ַ�ת��Ϊ����
        ++it;                    //����������ƶ�
      }
      Push(opnd, x);
    } else {
      switch (Precede(GetTop(optr), *it)) {  //�������ȼ��ıȽ�
        case '<':
          Push(optr, *it);
          ++it;
          break;
        case '>':
          Pop(optr, theta);
          Pop(opnd, b);
          Pop(opnd, a);
          Push(opnd, Operate(a, theta, b));  //��������ѹ��opndջ
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
  return GetTop(opnd);  // opndջ��Ϊ���ʽ��ֵ���
}

int main() {
  int result = EvaluateExpression();  //��������
  cout << result << endl;
  system("pause");
  return SUCCESS;
}
