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
    static bool comp(std::vector<int> &a, std::vector<int> &b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        Trie t;
        // Initialize answers with -1 to indicate no valid XOR pair found
        vector<int> ans(m, -1); 
        
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(nums.begin(), nums.end());
        // sort queries based on m[i]
        sort(queries.begin(), queries.end(), comp);
        int i = 0, j = 0;
        // for (auto q: queries) {
        //     cout << q[0] << " " << q[1] << " " << q[2] << endl;
        // }
        while (j < m) {
            int num = queries[j][0];
            int limit = queries[j][1];

            // Insert all elements up to the limit into the Trie
            while (i < n && nums[i] <= limit) {
                t.insert(nums[i++]);
            }

        // If no element was inserted, i.e., all elements are greater than limit
            if (i == 0) {
                j++;
                continue;
            }

            int xorPair = t.getMaxXorPair(num);
            int idx = queries[j][2];
            // Update answer for the current query
            ans[idx] = num ^ xorPair;
            j++;
        }
        return ans;
    }
};