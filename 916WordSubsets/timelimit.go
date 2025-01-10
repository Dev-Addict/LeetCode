package timelimit

import "C"

func wordSubsets(words1 []string, words2 []string) []string {
	for _, subset := range words2 {
		letters := make(map[rune]int)

		for _, letter := range subset {
			letters[letter]++
		}

		var newWords1 = []string{}

	outer:
		for _, word := range words1 {
			lettersCopy := make(map[rune]int)

			for key, value := range letters {
				lettersCopy[key] = value
			}

			for _, letter := range word {
				if value, exists := lettersCopy[letter]; exists && value != 0 {
					lettersCopy[letter]--
				}
			}

			for _, numberOfLetters := range lettersCopy {
				if numberOfLetters != 0 {
					continue outer
				}
			}

			newWords1 = append(newWords1, word)
		}

		words1 = newWords1
	}

	return words1
}
