#include <vector>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
	    vector<int> count = vector<int>(value, 0);

	    for (int i = 0; i < nums.size(); i++) 
		    count[(nums[i] % value + value) % value]++;

	    for (int i = 0;; i++) {
		    if (count[i % value] == 0)
			    return i;

		    count[i % value]--;
	    }

	    return 0;
    }
};
