// Problem: Coin Change II
// Difficulty: medium
// Runtime: 1893 ms
// Memory: 710.7 MB

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        reverse(coins.begin(),coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(coins, amount, n, 0, dp);
    }

    int solve(vector<int> coins, int target, int n, int idx, vector<vector<int>>& dp){
        if(idx == n-1){
            if(target%coins[idx] == 0) return 1;
            return 0;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int take = 0;
        if(target>=coins[idx]) take = solve(coins, target-coins[idx], n, idx, dp);
        int notTake = solve(coins, target, n, idx+1, dp);

        return dp[idx][target] = take+notTake;
    }
};