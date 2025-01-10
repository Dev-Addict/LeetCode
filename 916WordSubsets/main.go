package main

import "C"

func countFrequencies(word string) []int {
	frequencies := make([]int, 26)

	for _, letter := range word {
		index := letter - 'a'
		frequencies[index]++
	}

	return frequencies
}

func wordSubsets(words1 []string, words2 []string) []string {
	maxFrequencies := make([]int, 26)

	for _, word := range words2 {
		frequencies := countFrequencies(word)

		for i := 0; i < 26; i++ {
			maxFrequencies[i] = max(maxFrequencies[i], frequencies[i])
		}
	}

	universalWords := []string{}

outer:
	for _, word := range words1 {
		frequencies := countFrequencies(word)

		for i := 0; i < 26; i++ {
			if maxFrequencies[i] > frequencies[i] {
				continue outer
			}
		}

		universalWords = append(universalWords, word)
	}

	return universalWords
}
