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

function isSymmetricSides(left: TreeNode | null, right: TreeNode | null): boolean {
  if (left === null || right === null) {
    return left === right;
  }

  return left.val === right.val && isSymmetricSides(left.left, right.right) && isSymmetricSides(left.right, right.left);
};

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function isSymmetric(root: TreeNode | null): boolean {
  if (root === null) {
    return true;
  }

  return isSymmetricSides(root.left, root.right);
};
