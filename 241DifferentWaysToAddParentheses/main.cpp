#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    vector<int> res;

    for (int i = 0; i < expression.size(); i++) {
      char op{expression[i]};

      if (op == '+' || op == '-' || op == '*') {
        vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
        vector<int> s2 = diffWaysToCompute(expression.substr(i + 1));
        for (int a : s1) {
          for (int b : s2) {
            switch (op) {
            case '+':
              res.push_back(a + b);
              break;
            case '-':
              res.push_back(a - b);
              break;
            case '*':
              res.push_back(a * b);
            }
          }
        }
      }
    }

    if (res.empty()) {
      res.push_back(stoi(expression));
    }

    return res;
  }
};
