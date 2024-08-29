#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_map<int, bool> record;

    while (n != 1) {
      string stringN = to_string(n);
      int newNum = 0;

      for (char c: stringN) {
        int digit = c - '0';

        newNum += digit * digit;
      }

      n = newNum;

      if (record[n]) {
        return false;
      }

      record[n] = true;
    }

    return true;
  }
};
