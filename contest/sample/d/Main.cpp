#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  long long a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;

  unordered_map<long long, long long> seen;
  long long current = a;
  long long day = 0;

  while (day < k) {
    if (seen.find(current) != seen.end()) {
      long long cycle_length = day - seen[current];
      long long remaining_days = k - day;
      day += (remaining_days / cycle_length) * cycle_length;

      while (day < k) {
        current = min(current * b - c, d);
        if (current < 0) {
          current = 0;
          break;
        }
        day++;
      }
      break;
    }

    seen[current] = day;

    current = min(current * b - c, d);

    if (current < 0) {
      current = 0;
      break;
    }

    day++;
  }

  cout << current << endl;
  return 0;
}