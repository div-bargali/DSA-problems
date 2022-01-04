// https://leetcode.com/problems/decode-xored-permutation/

// Explaination - https://bit.ly/3mU0Yz4
// observation is that first element is xor of all the odd elements of encoded with x (x is xor of elements from 1 - n)
// a ^ a = 0
// a ^ b = b ^ a
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size(), x = 0, first, next;
        vector<int> perm;
        
        // for(int i = 1; i <= n+1; ++i) x ^= i;
        if((n+1) % 4 == 3) x = 0;
        else if ((n+1) % 4 == 1) x = 1;
        first = x;
        for(int i = 1; i < n; i += 2) first ^= encoded[i];
        
        // now we have first element of perm
        perm.push_back(first);
        for(int i = 0; i < n; i++){
            next = perm[i] ^ encoded[i];
            perm.push_back(next);
        }
        
        return perm;
    }
};