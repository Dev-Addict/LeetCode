package main

import "math"

func checkPowersOfThree(n int) bool {
	return checkPowersOfThreeHelper(n, 1)
}

func checkPowersOfThreeHelper(n int, lastP int) bool {
	if n <= 4 {
		return n != 2
	}

	p := lastP + 1

	for int(math.Pow(3, float64(p))) <= n {
		if checkPowersOfThreeHelper(n-int(math.Pow(3, float64(p))), p) {
			return true
		}

		p++
	}

	return false
}
