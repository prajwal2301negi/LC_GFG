// Problem: Minimum Operations to Make Array Non Decreasing
// Difficulty: medium
// Runtime: 0 ms
// Memory: 136.8 MB

class Solution {
public:
    long long minOperations(vector<int>& nums) {
          long long ans = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                ans += nums[i] - nums[i + 1];
            }
        }
        return ans;
    }
};