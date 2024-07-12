#include<string>
using namespace std;

class Solution {
public:
  int maxScore(string s) {
    int left = 0, right = 0, maxScore = 0;

    if (s[0] == '0')
      left = 1;

    for (int i = 1; i < s.length(); i++) 
      if (s[i] == '1')
        right++;

    maxScore = left + right;

    for (int i = 1; i < s.length() - 1; i++) {
      if (s[i] == '0') 
        left++;
      else
        right--;

      int score = left + right;

      if (score > maxScore)
        maxScore = score;
    }

    return maxScore;
  }
};

