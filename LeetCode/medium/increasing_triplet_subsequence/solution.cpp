// Problem: Increasing Triplet Subsequence
// Difficulty: medium
// Runtime: 0 ms
// Memory: 115.8 MB

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX,second=INT_MAX;
        for(int n:nums){
            if(n<=first) first=n;
            else if(n<=second) second=n;
            else return true;
        }return false;
    }
};