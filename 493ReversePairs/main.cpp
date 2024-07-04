#include <vector>
using namespace std;

class Solution {
	void merge(vector<int> &nums, int low, int mid, int high) {
		int *temp = new int[high - low + 1];

		int i = low;
		int j = mid + 1;
		int k = 0;

		while (i <= mid && j <= high) {
			if(nums[i] < nums[j]) {
				temp[k] = nums[i];
				i++;
			} else {
				temp[k] = nums[j];
				j++;
			}

			k++;
		}

		while (i <= mid) {
			temp[k] = nums[i];

			k++;
			i++;
		}
		while (j <= high) {
			temp[k] = nums[j];

			k++;
			j++;
		}

		for (int i = low; i <= high; i++)
			nums[i] = temp[i - low];
	}

	int countReversePairs(vector<int> &nums, int low, int mid, int high) {
		int right = mid + 1;
		int count = 0;

		for (int i = low; i <= mid; i++) {
			while (right <= high && (long)nums[i] > (long)2 * nums[right]) 
				right++;

			count += right - (mid + 1);
		}

		return count;
	}

	int mergeSort(vector<int> &nums, int low, int high) {
		if (low >= high) return 0;

		int count = 0;
		int mid = (low + high) / 2;

		count += mergeSort(nums, low, mid);
		count += mergeSort(nums, mid + 1, high);
		count += countReversePairs(nums, low, mid, high);

		merge(nums, low, mid, high);

		return count;
	}

public:
	int reversePairs(vector<int>& nums) {
		int cnt = mergeSort(nums, 0, nums.size() - 1);
		return cnt;
	}
};

