#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> SYMBOL_TO_VALUE{{'I', 1},   {'V', 5},   {'X', 10},
                                         {'L', 50},  {'C', 100}, {'D', 500},
                                         {'M', 1000}};

class Solution {
public:
  int romanToInt(string s) {
    int n = s.size();
    int result = 0;

    for (int i = 0; i < n; i++) {
      int symbolValue = SYMBOL_TO_VALUE[s[i]];

      if (symbolValue < SYMBOL_TO_VALUE[s[i + 1]]) {
        result -= symbolValue;
      } else {
        result += symbolValue;
      }
    }

    return result;
  }
};
