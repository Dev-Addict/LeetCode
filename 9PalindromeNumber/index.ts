function isPalindrome(x: number): boolean {
  if (x === 0) {
    return true;
  }
  if (x < 0 || x % 10 === 0) {
    return false;
  }
}

