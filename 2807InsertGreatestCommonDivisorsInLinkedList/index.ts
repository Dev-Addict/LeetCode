class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

function greatestCommonDivisor(a: number, b: number) {
  if (b == 0) {
    return a;
  }

  return greatestCommonDivisor(b, a % b);
}

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function insertGreatestCommonDivisors(head: ListNode | null): ListNode | null {
  if (head === null) {
    return head;
  }

  let current: ListNode | null = head;

  while (current!.next !== null) {
    const greatestCommonDivisorNode = new ListNode(greatestCommonDivisor(current!.val, current!.next.val), current!.next);
    current!.next = greatestCommonDivisorNode;
    current = current!.next!.next;
  }

  return head;
};
