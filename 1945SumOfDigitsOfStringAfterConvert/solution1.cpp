#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int getLucky(string s, int k) {
    vector<int> digits;

    for (char c : s) {
      int num = c - 'a' + 1;
      if (num < 10) {
        digits.push_back(num);
      } else {
        digits.push_back(num % 10);
        digits.push_back(num / 10);
      }
    }

    int sum{0};

    for (int i = 0; i < k; i++) {
      for (int digit : digits) {
        sum += digit;
      }

      digits = vector<int>();

      while (sum != 0) {
        digits.insert(digits.begin(), sum % 10);
        sum /= 10;
      }

      sum = 0;
    }

    int result = 0;

    for (int digit : digits) {
      result *= 10;
      result += digit;
    }

    return result;
  }
};
