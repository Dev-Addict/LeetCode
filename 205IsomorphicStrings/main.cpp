#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    int n = s.size();
    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;

    for (int i = 0; i < n; i++) {
      if (sToT.find(s[i]) != sToT.end()) {
        if (tToS.find(t[i]) == tToS.end()) {
          return false;
        }
        if (sToT[s[i]] != t[i] || tToS[t[i]] != s[i]) {
          return false;
        }
      }  else {
        if (tToS.find(t[i]) != tToS.end()) {
          return false;
        }
        sToT[s[i]] = t[i];
        tToS[t[i]] = s[i];
      }
    }

    return true;
  }
};
