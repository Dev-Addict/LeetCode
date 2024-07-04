#include <vector>
using namespace std;

class Solution {
public:
	vector<int> targetIndices(vector<int>& nums, int target) {
		vector<int> result;

		for (int i = 0; i < nums.size(); i++) {
			int min = nums[i];
			int minIndex = 0;

			for (int j = i + 1; j < nums.size(); j++) 
				if (nums[j] < min) {
					min = nums[j];
					minIndex = j;
				}

			if (min > target) break;
			if (min == target)
				result.push_back(i);

			int temp = nums[i];
			nums[i] = min;
			nums[minIndex] = temp;
		}

		return result;
	}
};

