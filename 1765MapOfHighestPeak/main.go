package main

import "C"

type pair struct {
	i int
	j int
}

func highestPeak(isWater [][]int) [][]int {
	m, n := len(isWater), len(isWater[0])
	result := make([][]int, m)
	queue := []pair{}

	for i := 0; i < m; i++ {
		result[i] = make([]int, n)

		for j := 0; j < n; j++ {
			result[i][j] = -1

			if isWater[i][j] == 1 {
				queue = append(queue, pair{i: i, j: j})
				result[i][j] = 0
			}
		}
	}

	directions := []pair{{i: 0, j: 1}, {i: 1, j: 0}, {i: 0, j: -1}, {i: -1, j: 0}}

	for len(queue) != 0 {
		current := queue[0]
		queue = queue[1:]

		for _, direction := range directions {
			x, y := current.i+direction.i, current.j+direction.j

			if x >= 0 && x < m && y >= 0 && y < n && result[x][y] == -1 {
				result[x][y] = result[current.i][current.j] + 1
				queue = append(queue, pair{x, y})
			}
		}
	}

	return result
}
