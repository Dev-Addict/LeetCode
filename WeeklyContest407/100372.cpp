#include<string>
using namespace std;

class Solution {
public:
  string intToBinaryForward(int n) {
    string binary = "";

    while (n > 0) {
        binary += to_string(n % 2);
        n = n / 2;
    }

    return binary;
}

  int minChanges(int n, int k) {
    string binaryN = intToBinaryForward(n), binaryK = intToBinaryForward(k);

    if (binaryK.length() > binaryN.length())
      return -1;

    int changes = 0;

    for (int i = 0; i < binaryK.length(); i++) {
      if (binaryK[i] == binaryN[i])
        continue;
      if (binaryN[i] == '0')
        return -1;

      changes++;
    }

    for (int i = binaryK.length(); i < binaryN.length(); i++)
      if(binaryN[i] == '1')
        changes++;

    return changes;
  }
};

