// eslint-disable-next-line @typescript-eslint/no-unused-vars
function nthUglyNumber(n: number): number {
  const dp: number[] = new Array(n);

  let pointer2 = 0;
  let pointer3 = 0;
  let pointer5 = 0;

  dp[0] = 1;

  for (let i = 1; i < n; i++) {
    const next2 = dp[pointer2] * 2;
    const next3 = dp[pointer3] * 3;
    const next5 = dp[pointer5] * 5;

    dp[i] = Math.min(next2, next3, next5);

    if (next2 === dp[i]) ++pointer2;
    if (next3 === dp[i]) ++pointer3;
    if (next5 === dp[i]) ++pointer5;
  }

  return dp[n - 1];
}
