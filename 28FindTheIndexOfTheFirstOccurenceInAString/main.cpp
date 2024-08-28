#include <string>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n - m; i++) {
      bool isOccurence = true;

      for (int j = 0; j < m; j++) {
        if (haystack[i + j] != needle[j]) {
          isOccurence = false;
          break;
        }
      }

      if (isOccurence) {
        return i;
      }
    }

    return -1;
  }
};
