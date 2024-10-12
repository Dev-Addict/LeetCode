type MultidimensionalArray = (MultidimensionalArray | number)[];

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function* inorderTraversal(
  arr: MultidimensionalArray,
): Generator<number, void, unknown> {
  for (const element of arr) {
    if (Array.isArray(element)) {
      yield* inorderTraversal(element);
    } else {
      yield element;
    }
  }
}
