/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* cur = root;
        while(cur && cur->left) {
            Node* n = cur;
            while(n) {
                // connect the left and right child nodes correctly
                // for all nodes on this level
                n->left->next = n->right;
                if (n->next) {
                    n->right->next = n->next->left;
                }
                n = n->next;
            }
            cur->left->next = cur->right;
            
            // move to the lower level
            cur = cur->left;
        }
        return root;
    }
};