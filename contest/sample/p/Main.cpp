#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited) {
  visited[v] = true;
  for (size_t u = 0; u < adj.size(); ++u) {
    if (adj[v][u] && !visited[u]) {
      dfs(u, adj, visited);
    }
  }
}

bool isStronglyConnected(int n, const vector<vector<int>>& graph, int X) {
  vector<vector<int>> adj(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (graph[i][j] <= X) {
        adj[i][j] = 1;
      }
    }
  }

  vector<bool> visited(n, false);
  dfs(0, adj, visited);
  if (any_of(visited.begin(), visited.end(), [](bool v) { return !v; })) {
    return false;
  }

  vector<vector<int>> reversedAdj(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (adj[j][i]) {
        reversedAdj[i][j] = 1;
      }
    }
  }

  fill(visited.begin(), visited.end(), false);
  dfs(0, reversedAdj, visited);
  return !any_of(visited.begin(), visited.end(), [](bool v) { return !v; });
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> graph(n, vector<int>(n));
  int left = 0, right = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> graph[i][j];
      right = max(right, graph[i][j]);
    }
  }

  int answer = right;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (isStronglyConnected(n, graph, mid)) {
      answer = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << answer << endl;
  return 0;
}