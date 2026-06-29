/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* node, int maxSoFar) {
        int result = 0;

        if (node == nullptr) {
            return result;
        }

        int newMax = max(maxSoFar, node->val);

        if (node->val >= newMax) {
            result += 1;
        }

        if (node->left != nullptr) {
            result += goodNodes(node->left, newMax);
        }
        if (node->right != nullptr) {
            result += goodNodes(node->right, newMax);
        }

        return result;
    }

    int goodNodes(TreeNode* root) {
        return goodNodes(root, root->val);
    }
};
