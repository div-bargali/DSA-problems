// link - https://leetcode.com/problems/sort-colors/

// use 3 pointers approach - i, j, k (k from end)
// everything before i = 0
// btw i and j (inclusive) = 1
// after k = 2

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int in0 = 0, in1 = 0, in2 = arr.size() - 1;
        while(in1 <= in2){
            if(arr[in1] == 1) in1++;
            
            else if(arr[in1] == 0){
                swap(arr[in0], arr[in1]);
                in0++; in1++;
            }
            
            else{
                swap(arr[in1], arr[in2]);
                in2--;
            }
        }
    }
};