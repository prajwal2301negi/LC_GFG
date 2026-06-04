// Problem: Minimum Cost of Buying Candies With Discount
// Difficulty: easy
// Runtime: 0 ms
// Memory: 14.2 MB

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int total = 0;

        for(int i = 0; i < cost.size(); i++) {
            if(i % 3 != 2) {  // skip 3rd candy in each group
                total += cost[i];
            }
        }
        return total;
    }
};