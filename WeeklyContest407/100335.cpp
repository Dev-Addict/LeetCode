#include<string>
#include<vector>
using namespace std;

class Solution {
public:
  bool doesAliceWin(string s) {
    if (s.length() == 0)
      return false;

    vector<int> vowels;

    for (int i = 0; i < s.length(); i++)
      if (isVowel(s[i]))
        vowels.push_back(i);

    if (vowels.size() == 0)
      return false;

    return true;
  }

  bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      return true;
    return false;
  }
};

