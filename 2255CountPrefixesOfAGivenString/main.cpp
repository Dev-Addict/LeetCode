#include<vector>
#include<string>
using namespace std;

class Solution {
public:
  int countPrefixes(vector<string>& words, string s) {
    int count = 0;

    for (string word : words) {
      if (word.length() > s.length())
        continue;

      bool isPrefix = true;

      for (int i = 0; i < word.length(); i++)
        if (word[i] != s[i]) {
          isPrefix = false;
          break;
        }

      count += isPrefix;
    }

    return count;
  }
};

