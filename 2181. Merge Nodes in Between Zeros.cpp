/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *anshead = nullptr;
        ListNode *ans = nullptr;

        ListNode *node = head;
        bool inMode = false;
        while (node != nullptr) {
            if (node->val != 0) {
                if (!anshead) {
                    anshead = new ListNode(node->val);
                    ans = anshead;
                } else {
                    if (inMode) {
                        ans->val += node->val;
                    } else {
                        ListNode * newnode = new ListNode(node->val);
                        ans->next = newnode;
                        ans = ans->next;
                    }
                }
                inMode = true;
            } else {
                inMode = false;
            }
            node = node->next;
        }
        
        return anshead;
    }
};
