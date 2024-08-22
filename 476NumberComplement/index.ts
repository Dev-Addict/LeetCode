// eslint-disable-next-line @typescript-eslint/no-unused-vars
function findComplement(num: number): number {
  if (num == 0)
    return 0;
  return findComplement(num >> 1) * 2 + (num % 2 == 0 ? 1 : 0);
}
