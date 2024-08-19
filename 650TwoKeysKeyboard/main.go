package solution

import "C"

func minSteps(n int) int {
	if n == 1 {
		return 0
	}

	result := n

	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			result = min(result, minSteps(n/i)+i)
		}
	}

	return result
}
