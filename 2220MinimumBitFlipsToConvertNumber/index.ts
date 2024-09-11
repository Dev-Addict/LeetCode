// eslint-disable-next-line @typescript-eslint/no-unused-vars
function minBitFlips(start: number, goal: number): number {
  let xorResult = start ^ goal;
  let count = 0;

  while (xorResult != 0) {
    count += xorResult & 1;
    xorResult >>= 1;
  }

  return count;
};
