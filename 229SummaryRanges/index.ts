// eslint-disable-next-line @typescript-eslint/no-unused-vars
function summaryRanges(nums: number[]): string[] {
  const result: string[] = [];

  let start = 0;
  let current = 0;

  while (current < nums.length) {
    while (current < nums.length - 1 && nums[current + 1] == nums[current] + 1) {
      ++current;
    }

    if (current == start) {
      result.push(nums[current].toString());
    } else {
      result.push(nums[start].toString() + "->" + nums[current].toString());
    }

    ++current;
    start = current;
  }

  return result;
}
