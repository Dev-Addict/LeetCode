#include <string>
using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i{0};
    int n = s.size();
    int j{0};
    int m = t.size();

    while (i < n && j < m) {
      if (s[i] == t[j]) {
        i++;
        j++;
      } else {
        j++;
      }
    }

    return i == n;
  }
};
