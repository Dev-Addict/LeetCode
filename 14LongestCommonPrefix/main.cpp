#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> strs) {
    string result = strs[0];

    for (int i = 1; i < strs.size(); i++) {
      string newResult = "";
      int maxLength = min(result.size(), strs[i].size());

      for (int j = 0; j < maxLength; j++) {
        if (result[j] == strs[i][j]) {
          newResult.push_back(result[j]);
        } else {
          break;
        }
      }

      result = newResult;
    }

    return result;
  }
};
