#include<string>
using namespace std;

class Solution {
public:
  int maxOperations(string s) {
    int result = 0;
    int n = s.length();

    for (int i = 0; i < n - 1; i++) 
      if (s[i] == '1' && s[i + 1] == '0') {
        int j = i, resultFromStep = 1;

        while (s[j + 1] == '0') {
          swap(s[j], s[j + 1]);
          j++;
        }

        while (i - resultFromStep >= 0 && s[i - resultFromStep] == '1') {
          swap(s[j - resultFromStep], s[i - resultFromStep]);
          resultFromStep++;
        }

        result += resultFromStep;
        i = j;
      }

    return result;
  }
};

