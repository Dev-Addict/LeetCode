#include <algorithm>
#include <vector>
using namespace std;

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
  void inorder(TreeNode *root, vector<int> *array) {
    if (root == nullptr) {
      return;
    }

    inorder(root->left, array);
    array->push_back(root->val);
    inorder(root->right, array);
  }

  int getMinimumDifference(TreeNode *root) {
    vector<int> array;

    inorder(root, &array);

    int result = array[1] - array[0];

    for (int i = 2; i < array.size(); i++) {
      result = min(result, array[i] - array[i - 1]);
    }

    return result;
  }
};
