#include<string>
using namespace std;

class Solution {
public:
  string getSmallestString(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
      int int1 = s[i] - '0', int2 = s[i + 1] - '0';

      if (int2 < int1 && (int1 + int2) % 2 == 0) {
        char temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;

        return s;
      }
    }

    return s;
  }
};

