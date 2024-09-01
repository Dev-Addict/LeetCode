// eslint-disable-next-line @typescript-eslint/no-unused-vars
function mySqrt(x: number): number {
  if (x == 0 || x == 1) {
    return x;
  }

  let start = 1;
  let end = x;
  let mid = 0;

  while (start <= end) {
    mid = Math.floor(start + (end - start) / 2);

    const square = mid * mid

    if (square > x) {
      end = mid - 1;
    } else if (square == x) {
      return mid;
    } else {
      start = mid + 1;
    }
  }

  return end;
}
