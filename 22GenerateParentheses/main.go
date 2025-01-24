package main

import "C"

var combinations []string

func generateParenthesis(n int) []string {
	combinations = []string{}

	backtrack(n, "", 0, 0)

	return combinations
}

func backtrack(n int, current string, openPosition, closePosition int) {
	if len(current) == n*2 {
		combinations = append(combinations, current)
	}

	if openPosition < n {
		backtrack(n, current+"(", openPosition+1, closePosition)
	}

	if closePosition < openPosition {
		backtrack(n, current+")", openPosition, closePosition+1)
	}
}
