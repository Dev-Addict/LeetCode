#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getMinDistance(vector<int>& nums, int target, int start) {
		int length = nums.size();
		int max_shared_distance = min(start, length - start);

		for (int i = 0; i <= max_shared_distance; i++) 
			if (nums[start + i] == target || nums[start - i] == target) 
				return i;

		if (start > length - start)
			for (int i = 2 * start - length - 1; i >= 0; i--)
				if (nums[i] == target)
					return start - i;

		for (int i = 2 * start + 1; i < length; i++)
			if (nums[i] == target)
				return i - start;

		return -1;
	}
};
