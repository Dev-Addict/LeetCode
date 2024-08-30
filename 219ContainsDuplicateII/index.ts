// eslint-disable-next-line @typescript-eslint/no-unused-vars
function containsNearbyDuplicate(nums: number[], k: number): boolean {
  const map: { [k: number]: number } = {};

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] in map && i - map[nums[i]] <= k) {
      return true;
    }

    map[nums[i]] = i;
  }

  return false;
}
