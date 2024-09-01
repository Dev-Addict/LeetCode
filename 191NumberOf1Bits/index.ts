// eslint-disable-next-line @typescript-eslint/no-unused-vars
function hammingWeight(n: number): number {
  if (n == 0) {
    return 0;
  }

  const digit = n % 2;

  return digit + hammingWeight((n - digit) / 2);
};
