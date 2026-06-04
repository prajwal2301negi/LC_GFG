// Problem: Unique Paths
// Difficulty: medium
// Runtime: 3 ms
// Memory: 9.5 MB

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m,n,0,0, dp);
    }

    int solve(int m, int n, int row, int column, vector<vector<int>>& dp){
        if(row == m-1 and column == n-1) return 1;
        if(row>m || column>n) return 0;

        if(dp[row][column] != -1) return dp[row][column];

        int down = solve(m,n,row+1,column, dp);
        int right = solve(m,n,row,column+1, dp);

        return dp[row][column] = down+right;
    }
};