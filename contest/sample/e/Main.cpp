#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool canPlaceCows(const vector<int>& stalls, int K, int dist) {
  int count = 1;  // Первая корова встаёт в первый стойло
  int lastPosition = stalls[0];

  for (size_t i = 1; i < stalls.size(); i++) {
    if (stalls[i] - lastPosition >= dist) {
      count++;
      lastPosition = stalls[i];
      if (count == K)
        return true;
    }
  }
  return false;
}

int maxMinDistance(vector<int>& stalls, int K) {
  sort(stalls.begin(), stalls.end());

  int left = 1;
  int right = stalls.back() - stalls.front();
  int result = 0;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (canPlaceCows(stalls, K, mid)) {
      result = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return result;
}

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> stalls(N);
  for (int i = 0; i < N; i++) {
    cin >> stalls[i];
  }

  cout << maxMinDistance(stalls, K) << endl;
  return 0;
}