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
function averageOfLevels(root: TreeNode | null): number[] {
  if (root === null) {
    return [];
  }

  const result: number[] = [];
  let current: TreeNode[] = [];

  current.push(root);

  while (current.length != 0) {
    let sum = 0;
    const newCurrent: TreeNode[] = [];

    for (const node of current) {
      sum += node.val;

      if (node.left !== null) {
        newCurrent.push(node.left);
      }
      if (node.right !== null) {
        newCurrent.push(node.right);
      }
    }

    result.push(sum / current.length);
    current = newCurrent;
  }

  return result;
}
