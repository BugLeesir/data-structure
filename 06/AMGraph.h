#ifndef AMGRAPH
#define AMGRAPH
#define MVNum 100
#define infinite 32767
using namespace std;
#include <iostream>
#endif
template <typename V, typename A>
struct AMGraph {
  V vexs[MVNum];         // �����
  A arcs[MVNum][MVNum];  // �ڽӾ���
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
  cout << "������ͼ�Ķ������ͱ���" << endl;
  cin >> G.vexnum >> G.arcnum;
  cout<<"���������붥������"<<endl;
  for (int i = 0; i < G.vexnum; ++i) {
    // cout << "�������" << i + 1 << "���ڵ������" << endl;
    cin >> G.vexs[i];
  }
  for (int i = 0; i < G.vexnum; ++i)
    for (int j = 0; j < G.arcnum; ++j) G.arcs[i][j] = infinite;
  V v1, v2;
  A w;
  for (int k = 0; k < G.arcnum; ++k) {
    cout << "������ߵ�ͷ��β���Լ�Ȩֵ" << endl;
    cin >> v1 >> v2 >> w;
    int i = LocateVex(G, v1);
    int j = LocateVex(G, v2);
    G.arcs[i][j] = w;
    G.arcs[j][i] = G.arcs[i][j];
  }
  return;
}

template <typename V, typename A>
void DFS(AMGraph<V, A> G, int v) {  // ������ȱ���
  bool visited[G.vexnum] = {false};
  cout << v;
  visited[v] = true;
  for (int w = 0; w < G.vexnum; ++w) {
    if ((G.arcnum[v][w] != 0) && (!visited[w])) DFS(G, w);
  }
}