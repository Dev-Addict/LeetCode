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

    if (n == 0) {
      return 0;
    }

    int total{SYMBOL_TO_VALUE[s[0]]};
    int lastValue{SYMBOL_TO_VALUE[s[0]]};

    for (int i = 1; i < n; i++) {
      int symbolValue = SYMBOL_TO_VALUE[s[i]];

      if (total < symbolValue) {
        total = symbolValue - total;
      } else if (lastValue < symbolValue) {
        total += symbolValue - 2 * lastValue;
      } else {
        total += symbolValue;
      }

      lastValue = symbolValue;
    }

    return total;
  }
};
