package main

import "unicode"

func clearDigits(s string) string {
	i := 0
	for unicode.IsDigit(rune(s[i])) {
		i++
	}
	i++

	for i < len(s) {
		if unicode.IsDigit(rune(s[i])) {
			if unicode.IsDigit(rune(s[i-1])) {
				i++
			} else {
				s = s[:i-1] + s[i+1:]
				i--
			}
		} else {
			i++
		}
	}

	return s
}
