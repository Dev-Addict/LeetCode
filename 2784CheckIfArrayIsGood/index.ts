// eslint-disable-next-line @typescript-eslint/no-unused-vars
function isGood(nums: number[]): boolean {
  const repeats: number[] = [];

  for (const num of nums) {
    while (num > repeats.length) {
      repeats.push(0);
    }

    ++repeats[num - 1];
  }

  if (repeats[repeats.length - 1] != 2) {
    return false;
  }

  for (let i = 0; i < repeats.length - 1; i++) {
    if (repeats[i] != 1) {
      return false;
    }
  }

  return true;
}
