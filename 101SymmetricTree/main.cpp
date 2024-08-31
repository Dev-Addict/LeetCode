struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    return isSymmetricSides(root->left, root->right);
  }

  bool isSymmetricSides(TreeNode *left, TreeNode *right) {
    if (left == nullptr || right == nullptr) {
      return left == right;
    }

    return left->val == right->val &&
           isSymmetricSides(left->left, right->right) &&
           isSymmetricSides(left->right, right->left);
  }
};
