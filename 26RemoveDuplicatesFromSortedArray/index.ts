function removeDuplicates(nums: number[]): number {
  let repeats = 0;

  for (let i = 1; i < nums.length; i++) {
    if (nums[i] == nums[i - 1])
      repeats++;
    else
      nums[i - repeats] = nums[i];
  }

  return nums.length - repeats;
}

