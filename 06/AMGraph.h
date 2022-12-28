#ifndef AMGRAPH
#define AMGRAPH
#define MVNum 100
#define infinite 32767
using namespace std;
#include <iostream>
#endif
template <typename V, typename A>
struct AMGraph {
  V vexs[MVNum];         // 顶点表
  A arcs[MVNum][MVNum];  // 邻接矩阵
  int vexnum, arcnum;
};  // Adjacency Matrix Graph

template <typename V, typename A>
int LocateVex(AMGraph<V, A> G, V v) {
  for (int i = 0; i < G.vexnum; ++i) {
    if (G.vexs[i] == v) {
      return i;
    }
  }
  return -1;
}

template <typename V, typename A>
void CreateUDN(AMGraph<V, A>& G) {
  cout << "请输入图的顶点数和边数" << endl;
  cin >> G.vexnum >> G.arcnum;
  cout<<"请依次输入顶点名称"<<endl;
  for (int i = 0; i < G.vexnum; ++i) {
    // cout << "请输入第" << i + 1 << "个节点的名称" << endl;
    cin >> G.vexs[i];
  }
  for (int i = 0; i < G.vexnum; ++i)
    for (int j = 0; j < G.arcnum; ++j) G.arcs[i][j] = infinite;
  V v1, v2;
  A w;
  for (int k = 0; k < G.arcnum; ++k) {
    cout << "请输入边的头和尾，以及权值" << endl;
    cin >> v1 >> v2 >> w;
    int i = LocateVex(G, v1);
    int j = LocateVex(G, v2);
    G.arcs[i][j] = w;
    G.arcs[j][i] = G.arcs[i][j];
  }
  return;
}

template <typename V, typename A>
void DFS(AMGraph<V, A> G, int v) {  // 深度优先遍历
  bool visited[G.vexnum] = {false};
  cout << v;
  visited[v] = true;
  for (int w = 0; w < G.vexnum; ++w) {
    if ((G.arcnum[v][w] != 0) && (!visited[w])) DFS(G, w);
  }
}