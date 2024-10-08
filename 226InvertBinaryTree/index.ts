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
function invertTree(root: TreeNode | null): TreeNode | null {
  if (root === null) {
    return null;
  }

  const temp = root.right;
  root.right = root.left;
  root.left = temp;

  invertTree(root.right);
  invertTree(root.left);

  return root;
}
