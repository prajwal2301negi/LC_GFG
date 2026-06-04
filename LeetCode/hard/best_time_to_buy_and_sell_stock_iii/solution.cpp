// Problem: Best Time to Buy and Sell Stock III
// Difficulty: hard
// Runtime: 499 ms
// Memory: 225.4 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, n, 0, 2, 1, 0, dp);
    }

    int solve(vector<int>& prices, int n, int idx, int k, int flag, int purchased, vector<vector<vector<int>>>& dp){
        if(idx == n) return 0;

        if(dp[idx][flag][k] != -1) return dp[idx][flag][k];

        int profit = 0;
        if(flag == 1){
            int buy = -prices[idx]+solve(prices, n, idx+1, k, 0, prices[idx], dp);
            int skip = solve(prices, n, idx+1, k, 1, purchased, dp);
            profit = max(buy, skip);
        }

        if(flag == 0 and k>0 and prices[idx]>purchased){
            int sell = prices[idx]+solve(prices, n, idx+1,k-1, 1, 0, dp);
            int skip = solve(prices, n, idx+1, k, 0, purchased, dp);
            profit = max(sell, skip);
        }

        return dp[idx][flag][k] = profit;

    }
};