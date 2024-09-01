class Solution {
public:
  int mySqrt(int x) {
    if (x == 0 || x == 1) {
      return x;
    }

    int start{1};
    int end{x};
    int mid{0};

    while (start <= end) {
      mid = start + (end - start) / 2;

      long square = static_cast<long>(mid) * mid;

      if (square > x) {
        end = mid - 1;
      } else if (square == x) {
        return mid;
      } else {
        start = mid + 1;
      }
    }

    return end;
  }
};
