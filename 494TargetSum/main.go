package main

import "C"

func sumInts(nums []int) int {
	sum := 0

	for _, num := range nums {
		sum += num
	}

	return sum
}

func findTargetSumWays(nums []int, target int) int {
	sum := sumInts(nums)
	difference := sum - target

	if difference < 0 || difference%2 != 0 {
		return 0
	}

	difference /= 2

	n := len(nums)
	dp := make([][]int, n+1)

	for i := range dp {
		dp[i] = make([]int, difference+1)
	}

	dp[0][0] = 1

	for i := 1; i <= n; i++ {
		for sum := 0; sum <= difference; sum++ {
			dp[i][sum] = dp[i-1][sum]

			if sum >= nums[i-1] {
				dp[i][sum] += dp[i-1][sum-nums[i-1]]
			}
		}
	}

	return dp[n][difference]
}
