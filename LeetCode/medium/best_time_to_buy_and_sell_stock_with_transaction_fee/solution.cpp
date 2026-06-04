// Problem: Best Time to Buy and Sell Stock with Transaction Fee
// Difficulty: medium
// Runtime: 130 ms
// Memory: 108.5 MB

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, n, 0, 1, dp, fee);
    }

    int solve(vector<int>& prices, int n, int idx, int flag, vector<vector<int>>& dp, int fee) {
        if (idx >= n) return 0;

        if (dp[idx][flag] != -1) return dp[idx][flag];

        int profit = 0;
        if (flag == 1) { 
            int buy = -prices[idx] + solve(prices, n, idx + 1, 0, dp, fee);
            int skip = solve(prices, n, idx + 1, 1, dp, fee);
            profit = max(buy, skip);
        } 
        else { 
            int sell = (prices[idx] - fee) + solve(prices, n, idx + 1, 1, dp, fee);
            int skip = solve(prices, n, idx + 1, 0, dp, fee);
            profit = max(sell, skip);
        }

        return dp[idx][flag] = profit;
    }

};