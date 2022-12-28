#include <cstdlib>
#include <ctime>
#include <iostream>

#include "HashTable.h"
using namespace std;

int main() {
  int arr[100];
  srand((int)time(0));
  for (int i = 0; i < 100; ++i) {//��ʼ�����������
    arr[i] = rand() % 10000 + 1;
    cout << arr[i] << ' ';
  }
  HashTable<int> ht;
  NewHashTable(ht);
  CreateHashTable(ht, arr, 100);
  while (1) {
    cout << endl;
    cout << "������Ҫ���ҵ���" << endl;
    int to_search;
    cin >> to_search;
    int result = FindValue(ht, to_search);
    if (result != -1) {
      cout << "�ҵ������ڱ���" << endl;
      cout<<"ֵΪ"<<result<<endl;
    } else {
      cout << "δ�ҵ�" << endl;
    }
  }
  return 0;
}