#include<string>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
      int ones = 0, zeroes = 0;

      for (int j = i; j < s.length(); j++) {
        ones += s[j] == '1';
        zeroes += s[j] == '0';

        if (ones >= zeroes * zeroes)
          result++;
      }
    }

    return result;
  }
};

