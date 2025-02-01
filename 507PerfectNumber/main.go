package main

import "C"
import "math"

func checkPerfectNumber(num int) bool {
	if num <= 1 {
		return false
	}

	sum := 1
	sqrtNum := int(math.Sqrt(float64(num)))

	for i := 2; i <= sqrtNum; i++ {
		if num%i == 0 {
			sum += i

			other := num / i
			if i != other {
				sum += other
			}
		}
	}

	return sum == num
}
