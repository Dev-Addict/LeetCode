package main

import "C"

func maxAscendingSum(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}

	currentSum, maxSum := nums[0], nums[0]

	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			currentSum += nums[i]
		} else {
			currentSum = nums[i]
		}

		maxSum = max(maxSum, currentSum)
	}

	return maxSum
}
