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
    int maxDepth(TreeNode* node, int curDepth) {
        if (node == nullptr) {
            return curDepth;
        }
        return max(maxDepth(node->left, curDepth + 1), maxDepth(node->right, curDepth + 1));
    }

    int maxDepth(TreeNode* root) {
        return maxDepth(root, 0);
    }
};
