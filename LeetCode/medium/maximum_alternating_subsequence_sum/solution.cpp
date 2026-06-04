// Problem: Maximum Alternating Subsequence Sum
// Difficulty: medium
// Runtime: 309 ms
// Memory: 166.5 MB

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<vector<long long>> dp(n, vector<long long>(2, -1));    

        return solve(nums, 0, 1, dp);
    }

    long long solve(vector<int>& nums, int idx, int flag, vector<vector<long long>>& dp) {
        if (idx == nums.size())
            return 0;

        if(dp[idx][flag] != -1) return dp[idx][flag];    

        long long take = 0;
        if (flag == true) {
            take = nums[idx] + solve(nums, idx + 1, 0, dp);
        } else
            take = -nums[idx] + solve(nums, idx + 1, 1, dp);

        long long skip = solve(nums, idx + 1, flag, dp);

        return dp[idx][flag] = max(take, skip);
    }
};