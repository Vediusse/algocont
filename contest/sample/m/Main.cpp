#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9;


const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dir[4] = {'N', 'E', 'S', 'W'};

int main() {
  int n, m;
  int start_x, start_y, end_x, end_y;

  cin >> n >> m;
  cin >> start_x >> start_y >> end_x >> end_y;


  start_x--;
  start_y--;
  end_x--;
  end_y--;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  vector<vector<int>> dist(n, vector<int>(m, INF));
  vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));
  deque<pair<int, int>> dq;

  dist[start_x][start_y] = 0;
  dq.push_front({start_x, start_y});

  while (!dq.empty()) {
    auto [x, y] = dq.front();
    dq.pop_front();

    for (int d = 0; d < 4; ++d) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
        int cost = (grid[nx][ny] == '.' ? 1 : 2);
        if (dist[nx][ny] > dist[x][y] + cost) {
          dist[nx][ny] = dist[x][y] + cost;
          prev[nx][ny] = {x, y};
          if (cost == 1) {
            dq.push_front({nx, ny});
          } else {
            dq.push_back({nx, ny});
          }
        }
      }
    }
  }

  if (dist[end_x][end_y] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[end_x][end_y] << endl;

    string path;
    int x = end_x, y = end_y;
    while (make_pair(x, y) != make_pair(start_x, start_y)) {
      auto [px, py] = prev[x][y];
      for (int d = 0; d < 4; ++d) {
        if (px + dx[d] == x && py + dy[d] == y) {
          path += dir[d];
          break;
        }
      }
      x = px;
      y = py;
    }
    reverse(path.begin(), path.end());
    cout << path << endl;
  }

  return 0;
}