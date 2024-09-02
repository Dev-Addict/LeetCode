// eslint-disable-next-line @typescript-eslint/no-unused-vars
function chalkReplacer(chalk: number[], k: number): number {
  const n = chalk.length;
  let sum = 0;

  for (const num of chalk) {
    sum += num;
  }

  k = k % sum;

  let i = 0;

  while (chalk[i] <= k) {
    k -= chalk[i];
    i = (i + 1) % n;
  }

  return i;
}
