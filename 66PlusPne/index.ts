// eslint-disable-next-line @typescript-eslint/no-unused-vars
function plusOne(digits: number[]): number[] {
  const n = digits.length;

  for (let i = n - 1; i >= 0; i--) {
    if (digits[i] == 9) {
      digits[i] = 0;
    } else {
      digits[i]++;
      return digits;
    }
  }

  digits.unshift(1);

  return digits;
}

