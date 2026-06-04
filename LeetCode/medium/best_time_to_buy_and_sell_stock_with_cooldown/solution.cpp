// Problem: Best Time to Buy and Sell Stock with Cooldown
// Difficulty: medium
// Runtime: 1 ms
// Memory: 16.3 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return solve(prices, n, 0, 1, dp);
    }

    int solve(vector<int>& prices, int n, int idx,int flag, vector<vector<int>>& dp) {
        if (idx >= n) return 0;
        if (dp[idx][flag] != -1) return dp[idx][flag];

        int profit = 0;
        if (flag == 1) { 
            int buy = -prices[idx] + solve(prices, n, idx + 1, 0, dp);
            int skip = solve(prices, n, idx + 1, 1, dp);
            profit = max(buy, skip);
        } 
        else { 
            int sell = prices[idx] + solve(prices, n, idx + 2, 1, dp);
            int skip = solve(prices, n, idx + 1, 0, dp);
            profit = max(sell, skip);
        }

        return dp[idx][flag] = profit;
    }
};

    
