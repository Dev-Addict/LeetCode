package main

import "C"
import "math"

func grayCode(n int) []int {
	if n == 0 {
		return []int{0}
	}

	currentBase := 2
	result := make([]int, int(math.Pow(2.0, float64(n))))

	result[0] = 0
	result[1] = 1

	for i := 1; i < n; i++ {
		for j := 0; j < currentBase; j++ {
			result[currentBase+j] = result[currentBase-j-1] + currentBase
		}

		currentBase *= 2
	}

	return result
}
