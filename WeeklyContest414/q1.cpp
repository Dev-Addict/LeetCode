#include <string>
using namespace std;

class Solution {
public:
  string convertDateToBinary(string data) {
    string result{""};
    string currentNum{""};

    for (char c : data) {
      if (c == '-') {
        int num = stoi(currentNum);

        result += decimalToBinary(num) + '-';

        currentNum = "";
      } else {
        currentNum += c;
      }
    }

    int num = stoi(currentNum);

    result += decimalToBinary(num);

    return result;
  }

  string decimalToBinary(int num) {
    if (num == 0) {
      return "0";
    }

    string result{""};

    while (num != 0) {
      result = to_string(num % 2) + result;
      num /= 2;
    }

    return result;
  }
};
