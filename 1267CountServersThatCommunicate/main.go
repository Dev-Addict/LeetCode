package main

import "C"

func countServers(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	communicativeServerRows := make([]bool, m)
	result := 0

	for i, row := range grid {
		rowServers := 0

		for _, cell := range row {
			if cell == 1 {
				rowServers++
			}
		}

		if rowServers > 1 {
			result += rowServers
			communicativeServerRows[i] = true
		}
	}

	for i := 0; i < n; i++ {
		columnServers := 0
		countedServers := 0

		for j := 0; j < m; j++ {
			if grid[j][i] == 1 {
				columnServers++

				if communicativeServerRows[j] {
					countedServers++
				}
			}
		}

		if columnServers > 1 {
			result += columnServers - countedServers
		}
	}

	return result
}
