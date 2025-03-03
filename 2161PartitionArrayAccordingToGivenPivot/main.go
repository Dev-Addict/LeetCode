package main

func pivotArray(nums []int, pivot int) []int {
	var less, more []int
	pivotCount := 0

	for _, num := range nums {
		if num == pivot {
			pivotCount++
		} else if num < pivot {
			less = append(less, num)
		} else {
			more = append(more, num)
		}
	}

	for i := 0; i < pivotCount; i++ {
		less = append(less, pivot)
	}

	less = append(less, more...)

	return less
}
