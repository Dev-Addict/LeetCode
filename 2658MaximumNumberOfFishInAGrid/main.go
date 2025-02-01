package main

import "C"

func findMaxFish(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	result := 0

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			newResult := dfs(grid, i, j)

			if newResult > result {
				result = newResult
			}
		}
	}

	return result
}

func dfs(grid [][]int, row, col int) int {
	result := grid[row][col]
	directions := [][]int{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}

	grid[row][col] = 0

	for _, direction := range directions {
		x, y := row+direction[0], col+direction[1]

		if x >= 0 && x < len(grid) && y >= 0 && y < len(grid[0]) && grid[x][y] > 0 {
			result += dfs(grid, x, y)
		}
	}

	return result
}
