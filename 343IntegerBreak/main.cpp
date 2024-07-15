class Solution {
public:
  int integerBreak(int n) {
    int result = 0;

    for (int i = 2; i < n / 2 + 1; i++) {
      int nums[i];

      for (int j = 0; j < i; j++)
        nums[j] = n / i;

      int remainder = n % i;
      int index = 0;

      while (remainder > 0) {
        nums[index]++;
        index++;
        remainder--;
      }

      int product = numsProduct(nums, i);

      if (product > result)
        result = product;
    }

    return result;
  }

  int numsProduct(int nums[], int size) {
    int result = 1;

    for (int i = 0; i < size; i++)
      result *= nums[i];

    return result;
  }
};

