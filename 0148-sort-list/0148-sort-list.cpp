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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        // find middle element of LL
        ListNode* slow = head, *fast = head, *prev = nullptr;
        while(fast && fast->next) {
            prev = slow; // keeps track of 1 node before slow
            slow = slow->next;
            fast = fast->next->next;
        }
        // split the LL into 2, first's head is head, second's head is slow
        if (prev) prev->next = nullptr; 
        ListNode* leftHead = sortList(head); // mergeSort recursion
        ListNode* rightHead = sortList(slow); // divides list further down until 1 element or no element
        return merge(leftHead, rightHead);
    }
private:
    ListNode* merge(ListNode* left, ListNode* right) {
        // code for merge 2 sorted LL list
        ListNode* dummy = new ListNode(); 
        ListNode* tail = dummy; // tail is pointer to dummy Node

        while(left && right){
            if(left->val <= right->val){
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        // one of the list is completely iterated, and the remaining 
        // part of second is already sorted so just link tail to first node
        // of remaining list
        tail->next = left ? left : right;
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};