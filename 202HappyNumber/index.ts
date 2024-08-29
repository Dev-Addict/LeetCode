// eslint-disable-next-line @typescript-eslint/no-unused-vars
function isHappy(n: number): boolean {
  const record: {[k: number]: boolean} = {};

  while (n !== 1) {
    let newNum = 0;

    while (n !== 0) {
      const digit = n % 10;
      n = (n - digit) / 10;

      newNum += digit * digit;
    }

    n = newNum;

    if (record[n]) {
      return false;
    }

    record[n] = true;
  }

  return true;
}
