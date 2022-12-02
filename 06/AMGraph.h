#define MVNum 100
#define infinite 32767

template <typename V, typename A>
struct AMGraph {
  V vexs[MVNum];         //¶¥µã±í
  A arcs[MVNum][MVNum];  //ÁÚ½Ó¾ØÕó
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
  cin >> G.vexnum >> G.arcnum;
  for (int i = 0; i < G.vexnum; ++i) cin >> G.vexs[i];
  for (int i = 0; i < G.vexnum; ++i)
    for (int j = 0; j < G.arcnum; ++j) G.arcnum[i][j] = infinite;
  V v1, v2;
  A w;
  for (int k = 0; k < G.arcnum; ++k) {
    cin >> v1 >> v2 >> w;
    int i = LocateVex(G, v1);
    int j = LocateVex(G, v2);
    G.arcs[i][j] = w;
    G.arcs[j][i] = G.arcs[i][j];
  }
  return;
}
