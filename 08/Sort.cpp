#ifndef Sort_CPP
#define Sort_CPP
#include "Sort.h"

#endif

void select_sort(SqTable &S) {//选择排序
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
                [min_index];  // 每次循环进行选择，将剩余部分中最小的数选出放在已经拍好序的部分后面
        S.Table[min_index] = temp;
        select_swap++;
      }
    }
  }
}

void insert_sort(SqTable &S) {//插入排序
  int temp;
  for (int i = 0; i < S.length; ++i) {
    for (int j = i + 1; j > 0; --j) {
      if (S.Table[j] <
          S.Table
              [j -
               1]) {  // 在要排序的一组数中，假定前n-1个数已经排好序，现在将第n个数插到前面的有序数列中，使得这n个数也是排好顺序的。如此反复循环，直到全部排好顺序。
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

void quick_sort(SqTable &S, int begin, int end) {  // 快速排序
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
  quick_sort(S, begin, i - 1);//递归调用
  quick_sort(S, i + 1, end);
}

void shell_sort(SqTable &S) {  // 希尔排序
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