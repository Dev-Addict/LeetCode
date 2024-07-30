#include<string>
using namespace std;

class Solution {
public:
  int minimumDeletions(string s) {
    int result = 0, bs = 0;

    for (char& c : s) {
      if (c == 'b')
        ++bs;
      else
        result = min(result + 1, bs);
    }

    return result;
  }
};

