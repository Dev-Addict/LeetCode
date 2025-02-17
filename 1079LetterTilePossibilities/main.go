package main

func numTilePossibilities(tiles string) int {
	frequencies := map[rune]int{}

	for _, tile := range tiles {
		frequencies[tile]++
	}

	remainingCounts := []int{}

	for _, count := range frequencies {
		remainingCounts = append(remainingCounts, count)
	}

	var backtrack func([]int) int
	backtrack = func(remainingCounts []int) int {
		result := 0

		for i := 0; i < len(remainingCounts); i++ {
			if remainingCounts[i] > 0 {
				remainingCounts[i]--
				result += 1 + backtrack(remainingCounts)
				remainingCounts[i]++
			}
		}

		return result
	}

	return backtrack(remainingCounts)
}
