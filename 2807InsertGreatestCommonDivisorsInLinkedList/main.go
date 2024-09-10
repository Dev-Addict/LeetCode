package solution

import "C"

type ListNode struct {
    Val int
    Next *ListNode
}

func greatestCommonDivisor(a int, b int) int {
  if b == 0 {
    return a
  }

  return greatestCommonDivisor(b, a % b)
}

func insertGreatestCommonDivisors(head *ListNode) *ListNode {
  if head == nil {
    return nil;
  }

  current := head;

  for current.Next != nil {
    greatestCommonDivisorNode := &ListNode{Val: greatestCommonDivisor(current.Val, current.Next.Val), Next: current.Next}
    current.Next = greatestCommonDivisorNode;
    current = current.Next.Next;
  }

  return head;
}
