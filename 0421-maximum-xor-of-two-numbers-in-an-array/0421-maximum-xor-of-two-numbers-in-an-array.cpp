class TrieNode {
public:
    TrieNode* links[2]; // 0 or 1
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int n) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1; // check if i-th bit is set
            if (cur->links[bit] == nullptr) {
                cur->links[bit] = new TrieNode();
            }
            cur = cur->links[bit];
        }
    }
    
    // returns the number that generates max XOR value with num
    int getMaxXorPair(int num) {
        TrieNode* cur = root;
        int xorPair = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // find i'th bits value of n
            int xorBit = 1 ^ bit;
            // check if xorBit exists in Trie
            if (cur->links[xorBit] != nullptr) {
                xorPair = xorPair | (xorBit << i);
                cur = cur->links[xorBit];
            } else {
                xorPair = xorPair | (bit << i);
                cur = cur->links[bit];
            }
        }
        return xorPair;
    }  
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int ans = 0;
        
        for (auto num: nums) {
            t.insert(num); // insert all nums in a trie in binary representation
        }
        
        for (auto num: nums) {
            int maxPossible = t.getMaxXorPair(num);
            ans = max(ans, num ^ maxPossible);
            
        }
        
        return ans;
    }
};