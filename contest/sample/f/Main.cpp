#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool customCompare(const string& a, const string& b) {
  return a + b > b + a;
}

int main() {
  vector<string> parts;
  string part;

  while (cin >> part) {
    parts.push_back(part);
  }

  sort(parts.begin(), parts.end(), customCompare);

  for (const string& s : parts) {
    cout << s;
  }
  cout << endl;

  return 0;
}