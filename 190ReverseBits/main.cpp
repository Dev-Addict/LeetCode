#include <cstdint>
using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    while (n != 0) {
      result = result * 2 + n % 2;
      n /= 2;
    }

    return result;
  }
};
