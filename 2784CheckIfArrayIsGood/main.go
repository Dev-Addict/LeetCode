package solution

import "C"

func isGood(nums []int) bool {
	var repeats []int

	for _, num := range nums {
		for num > len(repeats) {
			repeats = append(repeats, 0)
		}

		repeats[num-1]++
	}

	if repeats[len(repeats)-1] != 2 {
		return false
	}

	for i := 0; i < len(repeats)-1; i++ {
		if repeats[i] != 1 {
			return false
		}
	}

	return true
}
