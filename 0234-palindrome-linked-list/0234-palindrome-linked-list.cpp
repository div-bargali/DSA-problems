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
    bool isPalindrome(ListNode* head) {
        // find middle element
        // reverse the second half of LL and then do simple matching
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHead = reverse(slow);
        int dist = 0;
        while(head && secondHead) {
            if (head->val != secondHead->val) return false;
            head = head->next;
            secondHead = secondHead->next; dist++;
        }
        return true;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr, *nextNode;
        while(head) {
            nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
};