package main

func smallestNumber(pattern string) string {
	stack := make([]byte, 0, len(pattern)+1)
	result := make([]byte, 0, len(pattern)+1)

	for i := 0; i <= len(pattern); i++ {
		stack = append(stack, byte('1'+i))

		if i == len(pattern) || pattern[i] == 'I' {
			for j := len(stack) - 1; j >= 0; j-- {
				result = append(result, stack[j])
			}

			stack = stack[:0]
		}
	}

	return string(result)
}
