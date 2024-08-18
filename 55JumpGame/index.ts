// eslint-disable-next-line @typescript-eslint/no-unused-vars
function canJump(nums: number[]): boolean {
  let maxReach = 0;

  for (let i = 0; i < nums.length; i++) {
    if (maxReach < i)
      return false;

    maxReach = Math.max(maxReach, nums[i] + i);
  }

  return true;
}
