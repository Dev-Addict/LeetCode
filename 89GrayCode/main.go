package main

import "C"

func grayCode(n int) []int {
	if n == 0 {
		return []int{0}
	}

	currentBase := 2
	result := []int{0, 1}

	for i := 1; i < n; i++ {
		newResult := make([]int, currentBase*2)

		copy(newResult[:], result[:])

		for j := 0; j < currentBase; j++ {
			newResult[currentBase+j] = newResult[currentBase-j-1] + currentBase
		}

		currentBase *= 2
		result = newResult
	}

	return result
}
