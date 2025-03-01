#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  string input;
  cin >> input;

  deque<char> processQueue;
  unordered_map<int, int> matchPairs;
  vector<int> animalPositions, trapPositions;

  int animalTracker = 0, matchCounter = 0;

  for (size_t i = 0; i < input.size(); ++i) {
    char current = input[i];
    bool isAnimal = islower(current);

    if (isAnimal) {
      animalTracker++;
      animalPositions.push_back(animalTracker);
    } else {
      trapPositions.push_back(static_cast<int>(i) - animalTracker);
    }

    if (processQueue.empty()) {
      processQueue.push_back(current);
      continue;
    }

    if (tolower(current) != tolower(processQueue.back())) {
      processQueue.push_back(current);
      continue;
    }

    if (current != processQueue.back()) {
      matchPairs[trapPositions.back()] = animalPositions.back();
      trapPositions.pop_back();
      animalPositions.pop_back();
      processQueue.pop_back();
      matchCounter++;
    } else {
      processQueue.push_back(current);
    }
  }

  if (!processQueue.empty()) {
    cout << "Impossible" << endl;
    return 0;
  }

  cout << "Possible" << endl;
  for (int i = 0; i < matchCounter; ++i) {
    cout << matchPairs[i] << " ";
  }
  cout << endl;

  return 0;
}