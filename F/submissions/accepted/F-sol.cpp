#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
typedef struct Edge { int v; LL w;
  bool operator > (const Edge &b) const {
    return w > b.w;
  }
} S;
LL dijkstra(vector<vector<Edge> > &G, vector<LL> W, int s, int t) {
  priority_queue<S, vector<S>, greater<S> > pq;
  vector<LL> d(G.size(), INF);
  d[s] = W[s]; pq.push({s, d[s]});
  while (pq.size()) {
    auto p = pq.top(); pq.pop();
    if (p.v == t) return d[p.v];
    if (d[p.v] < p.w) continue;
    for (auto &e : G[p.v]) {
      if (d[e.v] > d[p.v] + e.w + W[e.v]) {
        d[e.v] = d[p.v] + e.w + W[e.v];
        pq.push({e.v, d[e.v]});
      }
    }
  }
  return INF;
}
void addEdge(vector<vector<Edge> > &G, int u, int v, LL w) {
    G[u].push_back({v, w});
    G[v].push_back({u, w});
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int> > A(n, vector<int>(n));
    for (auto &vv : A)
        for (auto &v : vv)
            cin >> v;
    vector<vector<int> > B(n, vector<int>(n));
    for (auto &vv : B)
        for (auto &v : vv)
            cin >> v;
    assert(1 < n && n <= 1000);
    for (auto &vv : A)
        for (auto &v : vv)
            assert(0 <= v && v <= 1000000);
    for (auto &vv : B)
        for (auto &v : vv)
            assert(0 <= v && v <= 1000000);
    int N = n - 1;
    int s = N * N + n * n;
    int t = s + 1;
    vector<vector<Edge> > G(N * N + n * n + 2);
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            int u = i * N + j, v; LL w;
            // U
            v = (i == 0     ? t : (i - 1) * N + (j + 0));
            w = A[i + 0][j + 0] + A[i + 0][j + 1];
            addEdge(G, u, v, w);
            // D
            v = (i == N - 1 ? s : (i + 1) * N + (j + 0));
            w = A[i + 1][j + 0] + A[i + 1][j + 1];
            addEdge(G, u, v, w);
            // L
            v = (j == 0     ? s : (i + 0) * N + (j - 1));
            w = A[i + 0][j + 0] + A[i + 1][j + 0];
            addEdge(G, u, v, w);
            // R
            v = (j == N - 1 ? t : (i + 0) * N + (j + 1));
            w = A[i + 0][j + 1] + A[i + 1][j + 1];
            addEdge(G, u, v, w);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            int u = N * N + i * n + j, v;
            // LU
            if (i == 0 || j == 0) {
            } else {
                v = (i - 1) * N + (j - 1);
                addEdge(G, u, v, 0);
            }
            // RU
            if (i == 0 || j == N)
                v = t;
            else
                v = (i - 1) * N + (j + 0);
            addEdge(G, u, v, 0);
            // RD
            if (i == N || j == N) {
            } else {
                v = (i + 0) * N + (j + 0);
                addEdge(G, u, v, 0);
            }
            // LD
            if (i == N || j == 0)
                v = s;
            else
                v = (i + 0) * N + (j - 1);
            addEdge(G, u, v, 0);
        }
    }
    vector<LL> W(N * N + n * n + 2, 0);
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            W[N * N + i * n + j] = B[i][j];
    cout << dijkstra(G, W, s, t) << '\n';
}
