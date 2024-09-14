class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function convertBST(
  nums: number[],
  left: number,
  right: number,
): TreeNode | null {
  if (left > right) {
    return null;
  }

  const mid = left + Math.floor((right - left) / 2);

  return new TreeNode(
    nums[mid],
    convertBST(nums, left, mid - 1),
    convertBST(nums, mid + 1, right),
  );
}

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function sortedArrayToBST(nums: number[]): TreeNode | null {
  return convertBST(nums, 0, nums.length - 1);
}
