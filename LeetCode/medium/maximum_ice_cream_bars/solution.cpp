// Problem: Maximum Ice Cream Bars
// Difficulty: medium
// Runtime: 35 ms
// Memory: 80.3 MB

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int i = 0;
        for (; i < costs.size(); i++) {
            coins -= costs[i];
            if (coins < 0) break;
        }

        return i;
    }
};