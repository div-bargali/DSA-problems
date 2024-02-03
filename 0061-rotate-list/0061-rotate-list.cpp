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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int len = 0;
        ListNode* cur = head, *tail;
        while(cur) {
            if (!cur->next) tail = cur;
            cur = cur->next; len++;  
        }
        k = k % len;
        if (k == 0) return head;
        cur = head;
        for (int i = 1; i < len-k; i++) {
            cur = cur->next;
        }
        tail->next = head;
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};