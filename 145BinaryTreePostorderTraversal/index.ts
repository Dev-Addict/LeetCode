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

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function postorderTraversal(root: TreeNode | null): number[] {
  const result: number[] = [];

  traverse(root, result);

  return result;
}

function traverse(root: TreeNode | null, array: number[]): void {
  if (root === null) {
    return;
  }

  traverse(root.left, array);
  traverse(root.right, array);

  array.push(root.val);
}
