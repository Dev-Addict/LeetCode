#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int length = 0, lastLength;

    for (char c : s) {
      if (c == ' ') {
        if (length != 0)
          lastLength = length;
        length = 0;
      } else
        length++;
    }

    if (length == 0)
      return lastLength;
    return length;
  }
};
