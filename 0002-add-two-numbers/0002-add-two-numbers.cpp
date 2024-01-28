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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        else if (!l2) return l1;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int sum = 0, carry = 0;
        while (l1 || l2) {
            sum = carry;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            
            ListNode* newNode = new ListNode(sum % 10);
            cur->next = newNode;
            
            carry = sum / 10;
            if (l1) l1 = l1->next; 
            if (l2) l2 = l2->next; 
            cur = cur->next;
        }
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            cur->next = newNode;
            cur = cur->next;
        }
        cur = dummy->next; // head of new LL
        delete dummy;
        return cur;
    }
};