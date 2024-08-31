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
  vector<double> averageOfLevels(TreeNode *root) {
    if (root == nullptr) {
      return vector<double>();
    }

    vector<double> result;

    vector<TreeNode *> current;

    current.push_back(root);

    while (current.size() != 0) {
      double sum{0};
      vector<TreeNode *> newCurrent;

      for (TreeNode *node : current) {
        sum += node->val;

        if (node->left != nullptr) {
          newCurrent.push_back(node->left);
        }
        if (node->right != nullptr) {
          newCurrent.push_back(node->right);
        }
      }

      result.push_back(sum / double(current.size()));
      current = newCurrent;
    }

    return result;
  }
};
