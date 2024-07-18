#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;

    if (digits.length() == 0)
      return result;

    unordered_map<char, string> digitsToLetters = {
      {'2', "abc"},
      {'3', "def"},
      {'4', "ghi"},
      {'5', "jkl"},
      {'6', "mno"},
      {'7', "pqrs"},
      {'8', "tuv"},
      {'9', "wxyz"},
    };

    for (char letter : digitsToLetters[digits[0]]) {
      string item;

      item.push_back(letter);
      result.push_back(item);
    }

    for (int i = 1; i < digits.length(); i++) {
      vector<string> newResult;

      for (char letter : digitsToLetters[digits[i]]) 
        for (string item : result) {
          item.push_back(letter);
          newResult.push_back(item);
        }

      result = newResult;
    }

    return result;
  }
};

