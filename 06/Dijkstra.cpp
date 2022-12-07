#ifndef Dijkstra_def
#define Dijkstra_def
#include <cstdio>
#include <iostream>

#include "AMGraph.h"
using namespace std;
#define MAX 514
#endif

int dis[MAX],
    path[MAX];  // dis�������·������Ȩֵ��pathͨ������·����ǰ�����������·��
bool book[MAX];  // ���ҵ������·���ļ���

template <typename V, typename A>
void Dijkstra(AMGraph<V, A> &G, int v0) {
  // �Ը�������г�ʼ��
  for (int v = 0; v < G.vexnum; v++) {
    book[v] = 0;
    dis[v] = G.arcs[v0][v];
    path[v] = 0;
  }
  // ������v0λ�±�Ķ���Ϊ��ʼ�㣬���Բ������ж�
  dis[v0] = 0;
  book[v0] = 1;
  int k = 0;
  for (int i = 0; i < G.vexnum; i++) {
    int min = infinite;
    // ѡ�񵽸�����Ȩֵ��С�Ķ��㣬��Ϊ������ȷ�����·���Ķ���
    for (int w = 0; w < G.vexnum; w++) {
      if (!book[w]) {
        if (dis[w] < min) {
          k = w;
          min = dis[w];
        }
      }
    }
    // ���øö���ı�־λΪ1�������´��ظ��ж�
    book[k] = 1;
    // ��v0���������Ȩֵ���и���
    for (int w = 0; w < G.vexnum; w++) {
      if (!book[w] && (min + G.arcs[k][w] < dis[w])) {
        dis[w] = min + G.arcs[k][w];
        path[w] = k;  // ��¼�������·���ϴ��ڵĶ���
      }
    }
  }
}

int main() {
  AMGraph<string, int> G;
  CreateUDN(G);
  int v0;
  cout << "����Ҫ�����Ǹ���������·��" << endl;
  cin >> v0;
  v0--;
  Dijkstra(G, v0);
  cout << "���·��Ϊ" << endl;
  for (int i = 1; i < G.vexnum; i++) {
    cout << i + 1 << "->" << v0 + 1 << "�����·���еĶ�����:";
    cout << i + 1 << "-";
    int j = i;
    // ����ÿһ�����·���϶���¼�ž����Ķ��㣬���Բ���Ƕ�׵ķ�ʽ������ɵõ��������·���ϵ����ж���
    while (path[j] != 0) {
      cout << path[j] + 1 << "-";
      j = path[j];
    }
    cout << v0 + 1 << endl;
  }
  cout << "Դ�㵽����������·������Ϊ:" << endl;
  for (int i = 0; i < G.vexnum; i++) {
    cout << G.vexs[v0] << "-" << G.vexs[i] << ":" << dis[i] << endl;
  }
  system("pause");
  return 0;
}