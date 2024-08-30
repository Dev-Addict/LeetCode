class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function mergeTwoLists(list1: ListNode | null, list2: ListNode | null) {
  if (list1 == null) {
    return list2;
  }
  if (list2 == null) {
    return list1;
  }

  let result: ListNode;

  if (list1.val < list2.val) {
    result = list1;
    list1 = list1.next;
  } else {
    result = list2;
    list2 = list2.next;
  }

  let current = result;

  while (list1 != null && list2 != null) {
    if (list1.val < list2.val) {
      current.next = list1;
      list1 = list1.next;
    } else {
      current.next = list2;
      list2 = list2.next;
    }

    current = current.next;
  }

  if (list1 == null) {
    current.next = list2;
  } else {
    current.next = list1;
  }

  return result;
}
