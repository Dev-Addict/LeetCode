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
function countNodes(root: TreeNode | null): number { 
  if (root === null) {
    return 0;
  }

  return 1 + countNodes(root.left) + countNodes(root.right);
}
