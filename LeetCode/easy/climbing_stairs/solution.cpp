// Problem: Climbing Stairs
// Difficulty: easy
// Runtime: 0 ms
// Memory: 8.7 MB

class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n, dp);
    }
    int solve(int n, vector<int>& dp){
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int step1 = solve(n-1, dp);
        int step2 = 0;
        if(n-step2>1) step2 = solve(n-2, dp);
        return dp[n] = step1+step2;
    }
};