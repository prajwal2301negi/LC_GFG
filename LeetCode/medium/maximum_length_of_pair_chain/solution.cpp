// Problem: Maximum Length of Pair Chain
// Difficulty: medium
// Runtime: 289 ms
// Memory: 163.4 MB

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        sort(pairs.begin(),pairs.end());
        return solve(pairs, 0, -1, dp);
    }

    int solve(vector<vector<int>>& nums, int idx, int prev_idx, vector<vector<int>>& dp) {
        if (idx == nums.size()) 
            return 0;

        if (dp[idx][prev_idx + 1] != -1) 
            return dp[idx][prev_idx + 1];

        int take = 0;
        if (prev_idx == -1 || nums[idx][0] > nums[prev_idx][1]) {
            take = 1 + solve(nums, idx + 1, idx, dp); 
        }
        int skip = solve(nums, idx + 1, prev_idx, dp);

        return dp[idx][prev_idx + 1] = max(take, skip);
    }
};