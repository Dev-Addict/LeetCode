#include <vector>
using namespace std;

int partition(vector<int> &values, int left, int right) {
	int pivot_index = left + (right - left) / 2;
	int pivot_value = values[pivot_index];
	int i = left, j = right;
	int temp;
	
	while(i <= j) {
		while(values[i] < pivot_value) {
			i++;
		}
		while(values[j] > pivot_value) {
			j--;
		}
		
		if(i <= j) {
			temp = values[i];
			values[i] = values[j];
			values[j] = temp;
			i++;
			j--;
		}
	}

	return i;
}

void quick_sort(vector<int> &values, int left, int right) {
    if(left < right) {
        int pivot_index = partition(values, left, right);

        quick_sort(values, left, pivot_index - 1);
        quick_sort(values, pivot_index, right);
    }
}

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int length = nums.size();

		quick_sort(nums, 0, length - 1);

		int posibility_one = nums[0] * nums[1] * nums[length - 1];
		int posibility_two = nums[length - 3] * nums[length - 2] * nums[length - 1];

		if (posibility_one > posibility_two)
			return posibility_one;
		return posibility_two;
	}
};

