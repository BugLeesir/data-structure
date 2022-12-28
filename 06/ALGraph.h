#ifndef ALGRAPH
#define ALGRAPH
#define MVNum 100
#include <iostream>

#include "Queue.h"
using namespace std;
#endif
template <typename O>
struct ArcNode {
  int adjvex;
  ArcNode<O> *nextarc;
  O info;
};

template <typename V, typename O>
struct VNode {
  V data;
  ArcNode<O> *firstarc;
};
template <typename V, typename O>
using AdjList = VNode<V, O>[MVNum];

template <typename V, typename A>
struct ALGraph {
  AdjList<V, A> vertices;
  int vexnum, arcnum;
};

int LocateVex(ALGraph<char, int> G, char v) {
  for (int i = 0; i < G.vexnum; ++i) {
    if (G.vertices[i].data == v) {
      return i;
    }
  }
  return -1;
}

void CreateUDG(ALGraph<char, int> &G) {
  cin >> G.vexnum >> G.arcnum;
  for (int i = 0; i < G.vexnum; ++i) {
    cin >> G.vertices[i].data;
    G.vertices[i].firstarc = nullptr;
  }
  char v1, v2;
  for (int k = 0; k < G.arcnum; ++k) {
    cin >> v1 >> v2;
    int i = LocateVex(G, v1);
    int j = LocateVex(G, v2);
    auto p1 = new ArcNode<int>;
    p1->adjvex = j;
    p1->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p1;
    auto p2 = new ArcNode<int>;
    p2->adjvex = i;
    p2->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = p2;
  }
}

int FirstAdjVex(ALGraph<char,int>G,int adjv){
    return G.vertices[adjv].firstarc->adjvex;
}

int NextAdjVex(ALGraph<char,int>G,int adjv,int fd){
    ArcNode<int>* p=G.vertices[adjv].firstarc;
    while(p){
        if(p->adjvex!=fd){
            return p->adjvex;
        }else{
            p=p->nextarc;
        }
    }
    return -1;
}

template<typename>
void BFS(ALGraph<char, int> G, int v) {// 广度优先遍历
  bool visited[G.vexnum] = {false};
  cout << v;
  visited[v] = true;
  QueuePtr<int> Q = nullptr;
  InitQueue(Q);
  EnQueue(Q, v);
  while (Q) {
    int u,w;
    DeQueue(Q, u);
    for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
    if(!visited[w]){
        cout<<w;
        visited[w]=true;
        EnQueue(Q,w);
    }
  }
}// BFS
