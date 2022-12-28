#ifndef Dijkstra_def
#define Dijkstra_def
#include <cstdio>
#include <iostream>

#include "AMGraph.h"
using namespace std;
#define MAX 514
#endif

int dis[MAX],
    path[MAX];  // dis保存最短路径的总权值，path通过保存路径的前驱结点来保存路径
bool book[MAX];  // 已找到的最短路径的集合

template <typename V, typename A>
void Dijkstra(AMGraph<V, A> &G, int v0) {
  // 对各数组进行初始化
  for (int v = 0; v < G.vexnum; v++) {
    book[v] = 0;
    dis[v] = G.arcs[v0][v];
    path[v] = 0;
  }
  // 由于以v0位下标的顶点为起始点，所以不用再判断
  dis[v0] = 0;
  book[v0] = 1;
  int k = 0;
  for (int i = 0; i < G.vexnum; i++) {
    int min = infinite;
    // 选择到各顶点权值最小的顶点，即为本次能确定最短路径的顶点
    for (int w = 0; w < G.vexnum; w++) {
      if (!book[w]) {
        if (dis[w] < min) {
          k = w;
          min = dis[w];
        }
      }
    }
    // 设置该顶点的标志位为1，避免下次重复判断
    book[k] = 1;
    // 对v0到各顶点的权值进行更新
    for (int w = 0; w < G.vexnum; w++) {
      if (!book[w] && (min + G.arcs[k][w] < dis[w])) {
        dis[w] = min + G.arcs[k][w];
        path[w] = k;  // 记录各个最短路径上存在的顶点
      }
    }
  }
}

int main() {
  AMGraph<string, int> G;
  CreateUDN(G);
  int v0;
  cout << "请输要查找那个顶点的最短路径" << endl;
  cin >> v0;
  v0--;
  Dijkstra(G, v0);
  cout << "最短路径为" << endl;
  for (int i = 1; i < G.vexnum; i++) {
    cout << i + 1 << "->" << v0 + 1 << "的最短路径中的顶点有:";
    cout << i + 1 << "-";
    int j = i;
    // 由于每一段最短路径上都记录着经过的顶点，所以采用嵌套的方式输出即可得到各个最短路径上的所有顶点
    while (path[j] != 0) {
      cout << path[j] + 1 << "-";
      j = path[j];
    }
    cout << v0 + 1 << endl;
  }
  cout << "源点到各顶点的最短路径长度为:" << endl;
  for (int i = 0; i < G.vexnum; i++) {
    cout << G.vexs[v0] << "-" << G.vexs[i] << ":" << dis[i] << endl;
  }
  system("pause");
  return 0;
}