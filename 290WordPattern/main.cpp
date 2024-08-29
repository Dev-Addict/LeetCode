#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> bridge;
    unordered_map<string, char> reverseBridge;

    int sIndex = 0;

    for (char c : pattern) {
      string word{};

      while (s[sIndex] != ' ' && sIndex < s.size()) {
        word += s[sIndex];
        sIndex++;
      }

      sIndex++;

      if (word.size() == 0) {
        return false;
      }

      if (bridge.find(c) != bridge.end()) {
        if (bridge[c] != word) {
          return false;
        }
      } else {
        bridge[c] = word;
      }

      if (reverseBridge.find(word) != reverseBridge.end()) {
        if (reverseBridge[word] != c) {
          return false;
        }
      } else {
        reverseBridge[word] = c;
      }
    }

    if (sIndex <= s.size()) {
      return false;
    }

    return true;
  }
};
