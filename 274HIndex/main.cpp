#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    vector<int> publishedOver(n + 1, 0);

    for (int citationNumber : citations)
      ++publishedOver[min(citationNumber, n)];

    int totalPublishedOver = 0, h = 0;

    for (int i = n; i >= 0; i--) {
      totalPublishedOver += publishedOver[i];

      h = max(h, min(totalPublishedOver, i));

      if (h == i)
        return h;
    }

    return h;
  }
};
