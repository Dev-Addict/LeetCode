#include<vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);

    return nums;
  }

  void mergeSort(vector<int>& nums, int low, int high) {
    if (low < high) 
      return;

    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);

    vector<int> newNums;

    int i = low, j = mid + 1;

    while (i <= mid && j <= high) {
      if (nums[i] > nums[j]) {
        newNums.push_back(nums[i]);
        i++;
      } else {
        newNums.push_back(nums[j]);
        j++;
      }
    }

    for (; i <= mid; i++)
      newNums.push_back(nums[i]);
    for (; j <= high; j++)
      newNums.push_back(nums[j]);

    cout << "Low: " << low << "\t High: " << high << "\n";
    for (int k = low; k <= high; k++) {
      cout << "k: " << k << "\t Num: " << newNums[k - low] << "\n";
      nums[k] = newNums[k - low];
    }
  }
};
