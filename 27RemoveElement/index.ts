function removeElement(nums: number[], val: number): number {
  const n = nums.length;
  let vals = 0;

  for (let i = 0; i < n; i++) {
    if (nums[i] == val)
      vals++
    else
      nums[i - vals] = nums[i];
  }

  return n - vals;
};
