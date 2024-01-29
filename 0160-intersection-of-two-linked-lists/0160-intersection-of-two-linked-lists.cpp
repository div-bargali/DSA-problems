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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0;
        ListNode* a = headA, *b = headB;
        while(a) {
            l1++; a = a->next;
        }
        while(b) {
            l2++; b = b->next;
        }
        if (l1 > l2) {
            while (l1 != l2) {
                l1--;
                headA = headA->next;
            }
        } else {
            while (l2 != l1) {
                l2--;
                headB = headB->next;
            }
        }
        while (headA && headB) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};