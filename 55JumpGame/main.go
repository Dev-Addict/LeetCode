package solution

import "C"

func canJump(nums []int) bool {
	var (
		maxReach = 0
		length   = len(nums)
	)

	for i := 0; i < length; i++ {
		if maxReach < i {
			return false
		}

		maxReach = max(maxReach, i+nums[i])
	}

	return true
}
