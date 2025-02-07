package main

import "C"

func tupleSameProduct(nums []int) int {
	record := map[int]int{}
	n := len(nums)
	result := 0

	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			record[nums[i]*nums[j]]++
		}
	}

	for _, count := range record {
		if count > 1 {
			result += count * (count - 1) * 4
		}
	}

	return result
}
