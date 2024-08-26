#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<char> VOWELS{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

class Solution {
public:
  string sortVowels(string s) {
    int n = s.size();
    unordered_map<char, int> vowels;
    vector<int> indices;

    for (int i = 0; i < n; i++) {
      if (isVowel(s[i])) {
        ++vowels[s[i]];
        indices.push_back(i);
      }
    }

    int i = 0;

    for (char vowel : VOWELS) {
      while (vowels[vowel] > 0) {
        s[indices[i++]] = vowel;
        --vowels[vowel];
      }
    }

    return s;
  }

private:
  bool isVowel(char c) {
    c = tolower(c);

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }
};
