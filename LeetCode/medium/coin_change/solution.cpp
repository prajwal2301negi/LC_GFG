// Problem: Coin Change
// Difficulty: medium
// Runtime: 54 ms
// Memory: 53 MB

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        reverse(coins.begin(),coins.end());
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, n, 0, dp);
        if(ans == 1e9) return -1;
        return ans;
    }

    int solve(vector<int>& nums, int target, int n, int idx, vector<vector<int>>& dp){
        if(idx == n-1){
            if(target%nums[idx] == 0) return target/nums[idx];
            return 1e9;
        }

        if(dp[idx][target] != -1) return dp[idx][target];
        
        int take = 1e9;
        if(target>=nums[idx]) take = 1+solve(nums, target-nums[idx], n, idx, dp);
        int notTake = solve(nums, target, n, idx+1, dp);

        return dp[idx][target] = min(take,notTake);
    }
};