#include <string>
using namespace std;

class Solution {
public:
  bool checkTwoChessboards(string coordinate1, string coordinate2) {
    int row1 = coordinate1[1] - '1';
    int col1 = coordinate1[0] - 'a';

    int row2 = coordinate2[1] - '1';
    int col2 = coordinate2[0] - 'a';

    return (row1 + col1) % 2 == (row2 + col2) % 2;
  }
};
