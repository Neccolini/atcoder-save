using Graph = vector<vector<int> >;
Graph G;

// v は現在見ている頂点, p は v の親
void dfs(int v, int p ) {
  for (auto nv : G[v]) {
    if (nv == p) continue;  // これがツリー探索で一般的な書き方
    dfs(nv, v);
  }
}

int main() {
  int root = 0;
  dfs(root, -1); // root の親はいないので -1
}