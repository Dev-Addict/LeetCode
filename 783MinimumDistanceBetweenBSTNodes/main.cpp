#include<cmath>
#include<limits.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(0), left(left), right(right) {}
};

class Solution {
  int minDifference;
  int previousValue;

public:
  int minDiffInBST(TreeNode* root) {
    minDifference = INT_MAX;
    previousValue = INT_MIN;

    inOrderTraversal(root);

    return minDifference;
  }

  void inOrderTraversal(TreeNode* node) {
    if (!node) return;

    inOrderTraversal(node->left);

    if (previousValue >= 0)
      minDifference = min(minDifference, abs(node->val - previousValue));

    previousValue = node->val;

    inOrderTraversal(node->right);
  }
};

