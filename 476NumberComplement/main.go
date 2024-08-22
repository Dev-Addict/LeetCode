package solution

import "C"

func findComplement(num int) int {
  if num == 0 {
    return 0
  }
  if num % 2 == 0 {
    return findComplement(num / 2) * 2 + 1
  }
  return findComplement(num / 2) * 2 + 0;
}
