#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long min_cost(int n, int k, vector<int>& prices) {
  sort(prices.rbegin(), prices.rend());
  long long total_cost = 0;

  for (int i = 0; i < n; i++) {
    if ((i % k) != k - 1) {
      total_cost += prices[i];
    }
  }
  return total_cost;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> prices(n);

  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }

  cout << min_cost(n, k, prices) << endl;
  return 0;
}