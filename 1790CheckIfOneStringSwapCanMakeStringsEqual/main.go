package main

import "C"

func areAlmostEqual(s1, s2 string) bool {
	mismatch := 0
	mismacthCharacters := make([]byte, 2)

	for i := 0; i < len(s1); i++ {
		if s1[i] != s2[i] {
			mismatch++

			if mismatch == 1 {
				mismacthCharacters[0] = s1[i]
				mismacthCharacters[1] = s2[i]
			}
			if mismatch == 2 && (mismacthCharacters[0] != s2[i] || mismacthCharacters[1] != s1[i]) {
				return false
			}
			if mismatch > 2 {
				return false
			}
		}
	}

	return mismatch != 1
}
