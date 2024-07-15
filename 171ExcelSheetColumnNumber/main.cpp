#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
  int titleToNumber(string columnTitle) {
    int number = 0;

    for (int i = 0; i < columnTitle.length(); i++) {
      number += (columnTitle[columnTitle.length() - i - 1] - 'A' + 1) * pow(26, i);
    }

    return number;
  }
};

