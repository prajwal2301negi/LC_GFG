// Problem: Best Time to Buy and Sell Stock II
// Difficulty: medium
// Runtime: 12 ms
// Memory: 27.9 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return solve(prices, n, 0, 1, 0, dp);
    }
    int solve(vector<int>& prices, int n, int idx, int flag, int purchased, vector<vector<int>>& dp){
        if(idx == n) return 0;

        if(dp[idx][flag] != -1) return dp[idx][flag];

        int profit = 0;
        if(flag == 1) {
            int buy = -prices[idx]+solve(prices, n, idx+1, 0, prices[idx], dp);
            int skip = solve(prices,n, idx+1, 1, purchased, dp);
            profit = max(buy, skip);
        }

        else if(flag == 0 and prices[idx]>purchased){
            int sell = (prices[idx]) + solve(prices, n, idx+1, 1, 0, dp);
            int skip = solve(prices, n, idx+1, 0, purchased, dp);
            profit = max(sell, skip);
        }

        return dp[idx][flag] = profit;
    }
};