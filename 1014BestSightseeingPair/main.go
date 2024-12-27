package main

import "C"

func maxScoreSightseeingPair(values []int) int {
	best := values[0]
	maxScore := 0

	for j := 1; j < len(values); j++ {
		score := best + values[j] - j
		if score > maxScore {
			maxScore = score
		}

		if values[j]+j > best {
			best = values[j] + j
		}
	}

	return maxScore
}
