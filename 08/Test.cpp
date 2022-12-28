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
  clock_t begin, end;  // 记录程序运行时间
  CreatSqTable(sq);
  RandomTable(sq);
  PrintSqTable(sq);
  begin = clock();
  cout << "select排序前" << begin << "ms" << endl;
  select_sort(sq);
  end = clock();
  PrintSqTable(sq);
  cout << "select排序后" << end << "ms" << endl;
  cout << "总计：" << end - begin << "ms" << endl;
  cout << "比较次数" << select_mov << "交换次数" << select_swap << endl;
  RandomTable(sq);
  // PrintSqTable(sq);
  begin = clock();
  cout << "insert排序前" << begin << "ms" << endl;
  insert_sort(sq);
  end = clock();
  // PrintSqTable(sq);
  cout << "insert排序后" << end << "ms" << endl;
  cout << "总计：" << end - begin << "ms" << endl;
  cout << "比较次数" << insert_mov << "交换次数" << insert_swap << endl;
  RandomTable(sq);
  // PrintSqTable(sq);
  begin = clock();
  cout << "shell排序前" << begin << "ms" << endl;
  shell_sort(sq);
  end = clock();
  // PrintSqTable(sq);
  cout << "shell排序后" << end << "ms" << endl;
  cout << "总计：" << end - begin << "ms" << endl;
  cout << "比较次数" << shell_mov << "交换次数" << shell_swap << endl;
  RandomTable(sq);
  // PrintSqTable(sq);
  begin = clock();
  cout << "quick排序前" << begin << "ms" << endl;
  quick_sort(sq, 0, sq.length);
  end = clock();
  // PrintSqTable(sq);
  cout << "quick排序后" << end << "ms" << endl;
  cout << "总计：" << end - begin << "ms" << endl;
  cout << "比较次数" << quick_mov << "交换次数" << quick_swap << endl;
  system("pause");
  return 0;
}