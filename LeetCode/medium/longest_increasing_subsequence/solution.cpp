// Problem: Longest Increasing Subsequence
// Difficulty: medium
// Runtime: 611 ms
// Memory: 296.6 MB

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(nums, n, 0, -1, dp);
    }

    int solve(vector<int>& nums, int n, int idx, int prev_idx, vector<vector<int>>& dp){
        if(idx >= n) return 0;

        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        int take = 0;
        if(prev_idx == -1 || nums[prev_idx]<nums[idx]) take = 1+solve(nums, n, idx+1, idx, dp);

        int notTake = solve(nums, n, idx+1, prev_idx, dp);

        return dp[idx][prev_idx+1] = max(take, notTake);
    }
};