#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
        vector<int> preorder(Node* root) {
                vector<int> result;

                if (root->val == 0) return result;

                result.push_back(root->val);

                for (int i = 0; i < root->children.size(); i++) {
                        vector<int> childResult = preorder(root->children[i]);

                        for (int i = 0; i < childResult.size(); i++) 
                                result.push_back(childResult[i]);
                }

                return result;
        }
};
