// Problem: Best Time to Buy and Sell Stock
// Difficulty: easy
// Runtime: 0 ms
// Memory: 97.3 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int ans = 0;
        int choose = prices[0];

        for(int i = 1;i<n;i++){
            int profitOnTheDay = prices[i] - choose;
            ans = max(ans,profitOnTheDay);
            choose = min(choose, prices[i]);
        }
        return ans;
    }
};