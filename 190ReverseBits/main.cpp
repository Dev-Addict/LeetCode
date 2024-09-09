#include <cmath>
#include <cstdint>
using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    if (n == 0) {
      return 0;
    }

    uint32_t result = 0;
    int length{0};

    while (n != 0) {
      result = result * 2 + n % 2;
      n /= 2;
      length++;
    }

    result = result * pow(2, 32 - length);

    return result;
  }
};
