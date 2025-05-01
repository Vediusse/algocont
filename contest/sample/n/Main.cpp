#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> key(n);
  for (int i = 0; i < n; ++i) {
    cin >> key[i];
    --key[i];
  }

  vector<bool> visited(n, false);
  int cycles = 0;

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      int curr = i;
      bool foundCycle = false;
      vector<bool> inStack(n, false);

      while (true) {
        if (visited[curr]) {
          break;
        }
        visited[curr] = true;
        inStack[curr] = true;

        int next = key[curr];
        if (inStack[next]) {
          foundCycle = true;
          break;
        }
        curr = next;
      }

      if (foundCycle) {
        ++cycles;
      }
    }
  }

  cout << cycles << endl;

  return 0;
}