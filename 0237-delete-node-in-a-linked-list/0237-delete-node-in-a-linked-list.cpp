/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int nextVal = node->next->val;
        node->val = nextVal; // copy next node's value to curr node
        node->next = node->next->next; // connect cur node directly to next of next
    }
};