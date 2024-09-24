#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<string, bool> prefixMap;

    for (int num : arr1) {
      string s{to_string(num)};
      string prefix{""};

      for (char c : s) {
        prefix += c;
        prefixMap[prefix] = true;
      }
    }

    int result{};

    for (int num : arr2) {
      string s{to_string(num)};
      string prefix{""};

      for (char c : s) {
        prefix += c;

        if (prefixMap.find(prefix) != prefixMap.end()) {
          result = max(result, static_cast<int>(prefix.size()));
        } else {
          break;
        }
      }
    }

    return result;
  }
};
