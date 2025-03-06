package main

func findMissingAndRepeatedValues(grid [][]int) []int {
	n := len(grid)
	supposedSum := n * n * (n*n + 1) / 2
	record := map[int]bool{}

	sum := 0
	repeated := 0

	for _, row := range grid {
		for _, item := range row {
			if record[item] {
				repeated = item
			}

			record[item] = true
			sum += item
		}
	}

	return []int{repeated, repeated + supposedSum - sum}
}
