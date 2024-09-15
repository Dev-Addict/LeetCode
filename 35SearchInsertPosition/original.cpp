#include <vector>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    return searchInsert(nums, target, 0, nums.size() - 1);
  }

  int searchInsert(vector<int> &nums, int target, int left, int right) {
    if (left > right) {
      return left;
    }

    int mid = left + (right - left) / 2;
    int num = nums[mid];

    if (num == target) {
      return mid;
    }

    if (num > target) {
      return searchInsert(nums, target, left, mid - 1);
    }

    return searchInsert(nums, target, mid + 1, right);
  }
};
