#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> count;

    for (char c: magazine) {
      ++count[c];
    }

    for (char c: ransomNote) {
      --count[c];
    }

    for (auto pair: count) {
      if (pair.second < 0) {
        return false;
      }
    }

    return true;
  }
};
