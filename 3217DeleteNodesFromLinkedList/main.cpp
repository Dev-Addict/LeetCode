#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    if (head == nullptr) {
      return head;
    }

    unordered_map<int, bool> record;

    for (int num : nums) {
      record[num] = true;
    }

    while (head != nullptr && record[head->val]) {
      head = head->next;
    }

    if (head == nullptr) {
      return head;
    }

    ListNode *current = head;

    while (current->next != nullptr) {
      if (record[current->next->val]) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }

    return head;
  }
};
