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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head, *tail;
        if (!list1) return list2;
        else if (!list2) return list1;
        if (list2->val < list1->val) {
            head = list2;
            list2 = list2->next;
        }
        else {
            head = list1;
            list1 = list1->next;
        }
        tail = head;
        
        while (list1 && list2) {
            if (list2->val < list1->val) {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            } else {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
        }
        // if one list is longer than the other
        if (list1) tail->next = list1;
        else if (list2) tail->next = list2;
        return head;
    }
};