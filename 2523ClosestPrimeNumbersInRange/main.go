package main

import "C"

import "math"

func closestPrimes(left int, right int) []int {
	result := []int{0, math.MaxInt}
	lastPrime := 0

	for i := left; i < right; i++ {
		if isPrime(i) {
			lastPrime = i
			break
		}
	}

	if lastPrime == 0 {
		return []int{-1, -1}
	}

	for i := lastPrime + 1; i <= right; i++ {
		if isPrime(i) {
			if i-lastPrime < result[1]-result[0] {
				if i-lastPrime <= 2 {
					return []int{lastPrime, i}
				}

				result[0] = lastPrime
				result[1] = i
			}

			lastPrime = i
		}
	}

	if result[0] == 0 {
		return []int{-1, -1}
	}

	return result
}

func isPrime(num int) bool {
	if num < 2 {
		return false
	}
	for i := 2; i < int(math.Sqrt(float64(num)))+1; i++ {
		if num%i == 0 {
			return false
		}
	}

	return true
}
