package main

import "C"

func longestMonotonicSubarray(nums []int) int {
	n := len(nums)

	if n < 2 {
		return n
	}

	increasing, decreasing, maximum := 1, 1, 1

	for i := 1; i < n; i++ {
		if nums[i] > nums[i-1] {
			increasing++
			decreasing = 1
		}

		if nums[i] < nums[i-1] {
			decreasing++
			increasing = 1
		}

		if nums[i] == nums[i-1] {
			increasing = 1
			decreasing = 1
		}

		maximum = max(increasing, decreasing, maximum)
	}

	return maximum
}
