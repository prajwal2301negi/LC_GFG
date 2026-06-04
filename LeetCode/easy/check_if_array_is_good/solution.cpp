// Problem: Check if Array is Good
// Difficulty: easy
// Runtime: 3 ms
// Memory: 26.3 MB

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int target = n - 1;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i + 1) return false;
            
        }
        return nums[n - 1] == target;
    }
};