#include <cstdlib>
#include <ctime>
#include <iostream>

#include "HashTable.h"
using namespace std;

int main() {
  int arr[100];
  srand((int)time(0));
  for (int i = 0; i < 100; ++i) {//初始化随机数数组
    arr[i] = rand() % 10000 + 1;
    cout << arr[i] << ' ';
  }
  HashTable<int> ht;
  NewHashTable(ht);
  CreateHashTable(ht, arr, 100);
  while (1) {
    cout << endl;
    cout << "请输入要查找的数" << endl;
    int to_search;
    cin >> to_search;
    int result = FindValue(ht, to_search);
    if (result != -1) {
      cout << "找到数据在表中" << endl;
      cout<<"值为"<<result<<endl;
    } else {
      cout << "未找到" << endl;
    }
  }
  return 0;
}