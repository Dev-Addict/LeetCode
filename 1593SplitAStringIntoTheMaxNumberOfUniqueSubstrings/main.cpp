#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int maxUniqueSplit(string s) {
    unordered_map<string, bool> seen;
    return backtrack(0, s, seen);
  }

  int backtrack(int start, const string &s, unordered_map<string, bool> &seen) {
    if (start == s.size()) {
      return 0;
    }

    int maxSplits{};

    for (int end = start + 1; end <= s.size(); end++) {
      string substring = s.substr(start, end - start);

      if (seen.find(substring) == seen.end()) {
        seen[substring] = true;
        maxSplits = max(maxSplits, 1 + backtrack(end, s, seen));
        seen.erase(substring);
      }
    }

    return maxSplits;
  }
};
