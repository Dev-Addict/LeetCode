struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *current = head;

    while (current->next != nullptr) {
      ListNode *greatestCommonDivisorNode =
          new ListNode(greatestCommonDivisor(current->val, current->next->val),
                       current->next);
      current->next = greatestCommonDivisorNode;
      current = current->next->next;
    }

    return head;
  }

  int greatestCommonDivisor(int a, int b) {
    if (b == 0) {
      return a;
    }

    return greatestCommonDivisor(b, a % b);
  }
};
