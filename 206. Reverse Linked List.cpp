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
    ListNode* reverseList(ListNode* head) {
        ListNode *newhead = nullptr;

        ListNode *node = head;
        while (node) {
            ListNode *next = node->next;
            node->next = newhead;
            newhead = node;
            node = next;
        }
        return newhead;
    }
};
