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
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr, *nextNode = head;
        while(head && head != tail) {
            nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
    ListNode* reverseKGroupRecursive(ListNode* head, int k) {
        if (!head) return nullptr;
        int count = 0; 
        ListNode* current = head, *newHead;
        // Count the number of nodes in the current group
        while (current && count < k) {
            current = current->next;
            count++;
        }
        // If the remaining list has fewer than k nodes, do not reverse
        if (count < k) {
            return head;
        }
        newHead = reverse(head, current);
        // Recursively reverse the next group
        head->next = reverseKGroup(current, k);
        // Return the new head of the reversed list
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        ListNode* currGrpHead = head, *currGrpTail, *prevGrpTail = nullptr, *nextGrpHead;
        while(currGrpHead) {
            currGrpTail = currGrpHead;
            for (int i = 1; i < k; i++) {
                if (currGrpTail) currGrpTail = currGrpTail->next;
            }
            // if currGrpTail becomes null, means there are less than k elements in group
            if (currGrpTail == nullptr) {
                break;
            }
            nextGrpHead = currGrpTail->next;
            // reverse the current group
            currGrpTail = currGrpHead; // after reverse head will become tail
            currGrpHead = reverse(currGrpHead, nextGrpHead);
            if (prevGrpTail == nullptr) {
                // dealing with the first group, make head point to the group head
                head = currGrpHead;
            } else {
                // connect previous reversed group with new one
                prevGrpTail->next = currGrpHead;
            }
            prevGrpTail = currGrpTail;
            currGrpHead = nextGrpHead;
        }
        if (currGrpHead) {
            prevGrpTail->next = currGrpHead;
        }
        return head;
    }
};