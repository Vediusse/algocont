#include <bits/stdc++.h>

using namespace std;

int main() {
  uint64_t n;
  cin >> n;

  uint64_t max_start = 1, max_end = 1;
  uint64_t max_len = 0;
  uint64_t cur_start = 1;

  int64_t cur_value, last_value = -1, pre_last_value = -2;

  for (uint64_t i = 1; i <= n; ++i) {
    cin >> cur_value;

    if (cur_value == last_value && cur_value == pre_last_value && i > 2) {
      cur_start = i - 1;
    }

    uint64_t cur_len = i - cur_start + 1;

    if (cur_len > max_len) {
      max_len = cur_len;
      max_start = cur_start;
      max_end = i;
    }

    pre_last_value = last_value;
    last_value = cur_value;
  }

  cout << max_start << " " << max_end << endl;

  return 0;
}