#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  unordered_map<string, vector<int>> variables;
  vector<string> scopeStack;

  string line;
  while (getline(cin, line)) {
    if (line == "{") {
      scopeStack.emplace_back("");
    } else if (line == "}") {
      while (!scopeStack.empty() && !scopeStack.back().empty()) {
        variables[scopeStack.back()].pop_back();
        scopeStack.pop_back();
      }
      scopeStack.pop_back();
    } else {
      size_t eqPos = line.find('=');
      string var1 = line.substr(0, eqPos);
      string var2 = line.substr(eqPos + 1);

      if (isdigit(var2[0]) || (var2[0] == '-' && isdigit(var2[1]))) {
        variables[var1].push_back(stoi(var2));
      } else {
        int value = variables[var2].empty() ? 0 : variables[var2].back();
        variables[var1].push_back(value);
        cout << value << endl;
      }
      scopeStack.push_back(var1);
    }
  }

  return 0;
}