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
    int maxLevelSum(TreeNode* root) {
        int max_sum = INT_MIN;
        int level = -1;

        if (!root) {
            return 0;
        }

        deque<TreeNode*> q;
        q.push_back(root);
        int j = 1;
        while(q.size() > 0) {
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                sum += node->val;
                q.pop_front();
                if (node->left) {
                    q.push_back(node->left);
                }
                if (node->right) {
                    q.push_back(node->right);
                }
            }
            if (sum > max_sum) {
                max_sum = sum;
                level = j;
            }
            j++;
        }

        return level;
    }
};
