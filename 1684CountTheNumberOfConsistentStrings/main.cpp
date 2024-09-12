#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> words) {
    unordered_map<char, bool> allowedMap;
    int count{0};

    for (char allowedChar : allowed) {
      allowedMap[allowedChar] = true;
    }

    for (string word : words) {
      bool notAllowed = false;

      for (char c : word) {
        if (!allowedMap[c]) {
          notAllowed = true;
          break;
        }
      }

      count += !notAllowed;
    }

    return count;
  }
};
