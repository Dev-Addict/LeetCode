#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    size_t n{min(a.size(), b.size())};
    size_t m{max(a.size(), b.size())};
    string result(m, '0');

    int carryOver{0};

    for (int i = 0; i < n; i++) {
      carryOver += (a[a.size() - i - 1] - '0') + (b[b.size() - i - 1] - '0');

      result[m - i - 1] = '0' + (carryOver % 2);
      carryOver /= 2;
    }

    for (int i = n; i < a.size(); i++) {
      carryOver += a[a.size() - i - 1] - '0';

      result[m - i - 1] = '0' + (carryOver % 2);
      carryOver /= 2;
    }

    for (int i = n; i < b.size(); i++) {
      carryOver += b[b.size() - i - 1] - '0';

      result[m - i - 1] = '0' + (carryOver % 2);
      carryOver /= 2;
    }

    if (carryOver) {
      result.insert(result.begin(), '1');
    }

    return result;
  }
};
