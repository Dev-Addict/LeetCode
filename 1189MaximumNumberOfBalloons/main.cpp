#include<string>
#include<unordered_map>
#include<limits.h>
using namespace std;

class Solution {
public:
  int maxNumberOfBalloons(string text) {        
    unordered_map<char, int> letters;
    unordered_map<char, int> neededLetters = {
      {'b', 1},
      {'a', 1},
      {'l', 2},
      {'o', 2},
      {'n', 1}
    };

    for (char letter : text)
    letters[letter]++;

    int result = INT_MAX;

    for (const auto& pair : neededLetters) {
      if (letters.find(pair.first) == letters.end()) {
        result = 0;
        break;
      }

      result = min(result, letters[pair.first] / pair.second);
    }

    return result;
  }
};

