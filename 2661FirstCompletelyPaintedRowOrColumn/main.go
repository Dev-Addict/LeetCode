package main

import "C"

func firstCompleteIndex(arr []int, mat [][]int) int {
	m := len(mat)
	n := len(mat[0])
	matrixIndices := make([][]int, m*n+1)

	for i, row := range mat {
		for j, value := range row {
			matrixIndices[value] = []int{i, j}
		}
	}

	paintInRow := make([]int, m)
	paintInCol := make([]int, n)

	for i, value := range arr {
		indices := matrixIndices[value]

		paintInRow[indices[0]]++
		paintInCol[indices[1]]++

		if paintInRow[indices[0]] == n || paintInCol[indices[1]] == m {
			return i
		}
	}

	return -1
}
