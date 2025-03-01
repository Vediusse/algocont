#include <iostream>
#include <string>
#include <vector>

bool checkString(const std::string& str) {
  int len = str.length();

  if (len % 2 != 0) {
    return false;
  }
  int mid = len / 2;
  for (int i = 0; i < mid; ++i) {
    if (str[i] != str[mid + i]) {
      return false;
    }
  }

  return true;
}

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();

  std::vector<std::string> lines(n);

  for (int i = 0; i < n; ++i) {
    std::getline(std::cin, lines[i]);
  }

  for (const auto& line : lines) {
    if (checkString(line)) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }

  return 0;
}