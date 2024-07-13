#include<algorithm>
using namespace std;

class Solution {
public:
  int maxRepOpt1(string text) {
    int result = 0;

    int frequency[26] = {0};

    for (int i = 0; i < text.length(); i++)
      frequency[text[i] - 'a']++;

    for (int i = 0; i < text.length() - result + 1; i++) {
      int j = 1;

      while (i + j < text.length() && text[i + j] == text[i]) 
        j++;

      j++;

      while (i + j < text.length() && text[i + j] == text[i]) 
        j++;

      result = max(result, min(j, frequency[text[i] - 'a']));
    }

    return result;
  }
};

