#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<int> color(n, -1);

  for (int i = 0; i < n; ++i) {
    if (color[i] == -1) {
      queue<int> q;
      q.push(i);
      color[i] = 0;

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
          if (color[v] == -1) {
            color[v] = 1 - color[u];
            q.push(v);
          } else if (color[v] == color[u]) {
            cout << "NO" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "YES" << endl;
  return 0;
}