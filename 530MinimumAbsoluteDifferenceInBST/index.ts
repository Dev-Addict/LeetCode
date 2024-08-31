class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}

function inorder(root: TreeNode | null, array: number[]): void {
  if (root === null) {
    return;
  }

  inorder(root.left, array);
  array.push(root.val);
  inorder(root.right, array);
}

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function getMinimumDifference(root: TreeNode | null): number {
  const array: number[] = [];

  inorder(root, array);

  let result = array[1] - array[0];

  for (let i = 2; i < array.length; i++) {
    result = Math.min(result, array[i] - array[i - 1]);
  }

  return result;
};
