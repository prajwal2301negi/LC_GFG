// Problem: Best Time to Buy and Sell Stock IV
// Difficulty: hard
// Runtime: 11 ms
// Memory: 18.5 MB

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(prices, n, 0, k, 1, dp);
    }

    int solve(vector<int>& prices, int n, int idx, int k, int flag, vector<vector<vector<int>>>& dp) {
        if (idx == n || k == 0) return 0;

        if (dp[idx][flag][k] != -1) return dp[idx][flag][k];

        int profit = 0;
        if (flag == 1) { 
            int buy = -prices[idx] + solve(prices, n, idx + 1, k, 0, dp);
            int skip = solve(prices, n, idx + 1, k, 1, dp);
            profit = max(buy, skip);
        } 
        else { 
            int sell = prices[idx] + solve(prices, n, idx + 1, k - 1, 1, dp);
            int skip = solve(prices, n, idx + 1, k, 0, dp);
            profit = max(sell, skip);
        }

        return dp[idx][flag][k] = profit;
    }
};