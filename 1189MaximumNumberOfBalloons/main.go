package main

import "C"

func maxNumberOfBalloons(text string) int {
	characters := make([]int, 26)

	for _, c := range text {
		characters[c-'a']++
	}

	return min(characters['b'-'a'], characters['a'-'a'], characters['l'-'a']/2, characters['o'-'a']/2, characters['n'-'a'])
}

func min(minNum int, nums ...int) int {
	for _, num := range nums {
		if num < minNum {
			minNum = num
		}
	}

	return minNum
}
