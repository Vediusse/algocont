#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> weights(26);
  for (int i = 0; i < 26; ++i) {
    cin >> weights[i];
  }

  vector<pair<char, int>> letter_weights;
  for (int i = 0; i < 26; ++i) {
    letter_weights.emplace_back('a' + i, weights[i]);
  }
  sort(
      letter_weights.begin(),
      letter_weights.end(),
      [](const pair<char, int>& a, const pair<char, int>& b) { return a.second > b.second; }
  );

  map<char, int> letter_count;
  for (char c : s) {
    letter_count[c]++;
  }

  int mid_index = 0;
  for (const auto& [letter, count] : letter_count) {
    if (count >= 2)
      mid_index++;
  }

  int left_index = 0;
  int right_index = s.length() - 1;

  vector<char> result(s.length());

  for (const auto& [letter, weight] : letter_weights) {
    if (letter_count[letter] >= 2) {
      result[left_index] = letter;
      result[right_index] = letter;
      left_index++;
      right_index--;
      letter_count[letter] -= 2;
    }

    while (letter_count[letter] > 0) {
      result[mid_index] = letter;
      mid_index++;
      letter_count[letter]--;
    }
  }

  for (char c : result)
    cout << c;
  return 0;
}