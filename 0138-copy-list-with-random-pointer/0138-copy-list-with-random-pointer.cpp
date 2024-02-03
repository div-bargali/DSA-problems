/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // STEP 1 - create copy nodes and place them in b/w of 2 nodes in original LL
        if (!head) return nullptr;
        Node* cur = head;
        while (cur) {
            Node* cur_cp = new Node(cur->val);
            cur_cp->next = cur->next; // place copy node in b/w cur and cur->next
            cur->next = cur_cp;
            cur = cur_cp->next;
        }
        // STEP 2 - assign random pointers to copied nodes
        cur = head;
        while(cur) {
            if (cur->random) {
                // next node of cur is the cur_cp
                // next node of cur->random will be cur->random's copy
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next; // since next node is copy node
        }
        // step 3 - break the links b/w copied and original LL
        cur = head;
        Node* head_cp = head->next;
        while(cur) {
            Node* cur_cp = cur->next;
            cur->next = cur_cp->next;
            if (cur->next) cur_cp->next = cur->next->next;
            cur = cur->next;
        }
        return head_cp;
    }
};