#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  bool isValid(string s, int start = 0) {
    if (s.size() == 0) {
      return true;
    }
    if (s.size() % 2 == 1) {
      return false;
    }

    for (int i = start; i < s.size() - 1; i++) {
      if ((s[i] == '(' && s[i + 1] == ')') || (s[i] == '{' && s[i + 1] == '}') ||
          (s[i] == '[' && s[i + 1] == ']')) {
        s.erase(i, 2);

        return isValid(s, max(i - 1, 0));
      }
    }

    return false;
  }
};
