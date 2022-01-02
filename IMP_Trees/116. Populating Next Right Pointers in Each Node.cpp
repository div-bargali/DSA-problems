// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// level order traversal - less optimised
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> bfs;
        bfs.push(root);
        while(!bfs.empty()){
            int n = bfs.size();
            Node* prev = NULL, *cur;
            for(int i = 0; i < n; i++){
                cur = bfs.front(); bfs.pop();
                if(prev) prev->next = cur;
                prev = cur;
                if(cur->left) bfs.push(cur->left);
                if(cur->right) bfs.push(cur->right);
            }
        }
        return root;
    }
};

// Space optimised BFS
// Explaination - https://bit.ly/3sXhiDh
// Basically level order traversal but in each level set next pointers of child nodes and traverse current level using next pointers of nodes on current level
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* head = root;
        while(root){
            Node* cur = root;
            while(cur){
                if(cur->left){
                    cur->left->next = cur->right; // left and right of left child connected
                    if(cur->next)
                        cur->right->next = cur->next->left; // right child of left has next now
                }
                cur = cur->next; // this step is like bfs
            }
            root = root->left;
        }
        return head;
    }
};
