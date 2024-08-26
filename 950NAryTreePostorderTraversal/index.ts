class _Node {
  val: number;
  children: _Node[];
  constructor(val?: number) {
    this.val = val === undefined ? 0 : val;
    this.children = [];
  }
}

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function postorder(root: _Node | null): number[] {
  const result: number[] = [];

  traverse(root, result);

  return result;
}

function traverse(root: _Node | null, result: number[]): void {
  if (root === null) {
    return;
  }

  for (const child of root.children) {
    traverse(child, result);
  }

  result.push(root.val);
}
