#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> bridge;
    int count{};

    for (char c : jewels) {
      bridge.insert(c);
    }

    for (char c : stones) {
      if (bridge.find(c) != bridge.end()) {
        ++count;
      }
    }

    return count;
  }
};
