#ifndef Main
#define Main
#include <ctime>
#include <iostream>

#include "Sort.h"
#include "SqTable.h"
using namespace std;
#endif
int main() {
  SqTable sq;
  clock_t begin, end;  // ��¼��������ʱ��
  CreatSqTable(sq);
  RandomTable(sq);
  PrintSqTable(sq);
  begin = clock();
  cout << "select����ǰ" << begin << "ms" << endl;
  select_sort(sq);
  end = clock();
  PrintSqTable(sq);
  cout << "select�����" << end << "ms" << endl;
  cout << "�ܼƣ�" << end - begin << "ms" << endl;
  cout << "�Ƚϴ���" << select_mov << "��������" << select_swap << endl;
  RandomTable(sq);
  // PrintSqTable(sq);
  begin = clock();
  cout << "insert����ǰ" << begin << "ms" << endl;
  insert_sort(sq);
  end = clock();
  // PrintSqTable(sq);
  cout << "insert�����" << end << "ms" << endl;
  cout << "�ܼƣ�" << end - begin << "ms" << endl;
  cout << "�Ƚϴ���" << insert_mov << "��������" << insert_swap << endl;
  RandomTable(sq);
  // PrintSqTable(sq);
  begin = clock();
  cout << "shell����ǰ" << begin << "ms" << endl;
  shell_sort(sq);
  end = clock();
  // PrintSqTable(sq);
  cout << "shell�����" << end << "ms" << endl;
  cout << "�ܼƣ�" << end - begin << "ms" << endl;
  cout << "�Ƚϴ���" << shell_mov << "��������" << shell_swap << endl;
  RandomTable(sq);
  // PrintSqTable(sq);
  begin = clock();
  cout << "quick����ǰ" << begin << "ms" << endl;
  quick_sort(sq, 0, sq.length);
  end = clock();
  // PrintSqTable(sq);
  cout << "quick�����" << end << "ms" << endl;
  cout << "�ܼƣ�" << end - begin << "ms" << endl;
  cout << "�Ƚϴ���" << quick_mov << "��������" << quick_swap << endl;
  system("pause");
  return 0;
}