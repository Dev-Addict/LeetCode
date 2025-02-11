package main

func removeOccurrences(s string, part string) string {
	m := len(part)

	for i := 0; i < len(s)-m+1; i++ {
		if s[i:i+m] != part {
			continue
		}

		s = s[:i] + s[i+m:]
		i = -1
	}

	return s
}
