// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// brute force - DFS with a vector
// optimised - find max and min node of each subtree O(n) TC, O(h) - h = height of tree S.C.
class Solution {
public:
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        maxMin(root);
        return ans;
    }
    
private:
    pair<int, int> maxMin(TreeNode* cur) {
        if(!cur->left && !cur->right) return make_pair(cur->val, cur->val);
        pair<int, int> l = {INT_MAX, INT_MIN}, r = {INT_MAX, INT_MIN};
        if(cur->left) l =  maxMin(cur->left);
        if(cur->right) r = maxMin(cur->right);
        
        int min_ = min(l.first, r.first);
        int max_ = max(l.second, r.second);
        
        ans = max({ans, abs(cur->val - min_), abs(max_ - cur->val)});
        return {min(min_, cur->val), max(max_, cur->val)};
    }
};