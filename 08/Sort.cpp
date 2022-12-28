#ifndef Sort_CPP
#define Sort_CPP
#include "Sort.h"

#endif

void select_sort(SqTable &S) {//ѡ������
  for (int i = 0; i < S.length; ++i) {
    int min_index = i;
    for (int j = i + 1; j < S.length; ++j) {
      if (S.Table[j] < S.Table[min_index]) {
        min_index = j;
        select_mov++;
      } else {
        select_mov++;
      }
      if (min_index != i) {
        int temp = S.Table[i];
        S.Table[i] =
            S.Table
                [min_index];  // ÿ��ѭ������ѡ�񣬽�ʣ�ಿ������С����ѡ�������Ѿ��ĺ���Ĳ��ֺ���
        S.Table[min_index] = temp;
        select_swap++;
      }
    }
  }
}

void insert_sort(SqTable &S) {//��������
  int temp;
  for (int i = 0; i < S.length; ++i) {
    for (int j = i + 1; j > 0; --j) {
      if (S.Table[j] <
          S.Table
              [j -
               1]) {  // ��Ҫ�����һ�����У��ٶ�ǰn-1�����Ѿ��ź������ڽ���n�����嵽ǰ������������У�ʹ����n����Ҳ���ź�˳��ġ���˷���ѭ����ֱ��ȫ���ź�˳��
        temp = S.Table[j];
        S.Table[j] = S.Table[j - 1];
        S.Table[j - 1] = temp;
        insert_swap++;
        insert_mov++;
      } else {
        insert_mov++;
        break;
      }
    }
  }
}

void quick_sort(SqTable &S, int begin, int end) {  // ��������
  if (begin >= end) return;
  int temp = S.Table[begin];
  int i = begin;
  int j = end;
  while (i < j) {
    while (S.Table[j] >= temp && j > i) {
      j--;
      quick_mov++;
    }
    if (i < j) {
      S.Table[i++] = S.Table[j];
      quick_swap++;
    }
    while (S.Table[i] <= temp && j > i) {
      i++;
      quick_mov++;
    }
    if (i < j) {
      S.Table[j--] = S.Table[i];
      quick_swap++;
    }
  }
  S.Table[i] = temp;
  quick_sort(S, begin, i - 1);//�ݹ����
  quick_sort(S, i + 1, end);
}

void shell_sort(SqTable &S) {  // ϣ������
  int gap, i, j;
  int temp;
  for (gap = S.length >> 1; gap > 0; gap >>= 1)
    for (i = gap; i < S.length; ++i) {
      temp = S.Table[i];
      for (j = i - gap; j >= 0 && S.Table[j] > temp; j -= gap)
        S.Table[j + gap] = S.Table[j];
      S.Table[j + gap] = temp;
      shell_swap++;
      shell_mov++;
    }
}