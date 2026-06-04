// Problem: Make Two Arrays Equal by Reversing Subarrays
// Difficulty: easy
// Runtime: 2 ms
// Memory: 18 MB

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        return target == arr; 
    }
};