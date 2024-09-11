class Solution {
public:
  int minBitFlips(int start, int goal) {
    int count{0};

    while (start != 0 || goal != 0) {
      count += start % 2 != goal % 2;
      start /= 2;
      goal /= 2;
    }

    return count;
  }
};
