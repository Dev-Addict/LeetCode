// eslint-disable-next-line @typescript-eslint/no-unused-vars
function minSteps(n: number): number {
  if (n == 1) return 0;

  let result = n;

  for (let i = 2; i * i <= n; ++i) 
    if (n % i == 0)
      result = Math.min(result, minSteps(n / i) + i);

  return result;
}

