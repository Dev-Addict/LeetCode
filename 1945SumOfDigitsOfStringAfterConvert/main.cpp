#include <string>
using namespace std;

class Solution {
public:
  int getLucky(string s, int k) {
    string num = "";

    for (char c : s) {
      num += to_string(c - 'a' + 1);
    }

    while (k > 0) {
      int sum = 0;

      for (char c: num) {
        sum += c - '0';
      }

      if (sum < 10 || k == 1) {
        return sum;
      }

      num = to_string(sum);
      k--;
    }

    return stoi(num);
  }
};
