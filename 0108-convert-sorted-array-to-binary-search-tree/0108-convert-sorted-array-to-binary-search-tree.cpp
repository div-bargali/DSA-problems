/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* divideTree(int start, int end, vector<int> &nums) {
        if (start > end) return nullptr;
        int mid = (end - start) / 2 + start;
        // mid node is always root
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = divideTree(start, mid-1, nums);
        root->right = divideTree(mid+1, end, nums);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        return divideTree(start, end, nums);
    }
};