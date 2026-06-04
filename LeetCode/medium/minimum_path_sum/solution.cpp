// Problem: Minimum Path Sum
// Difficulty: medium
// Runtime: 0 ms
// Memory: 16.4 MB

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(grid, n, m, 0, 0, dp);
    }

    int solve(vector<vector<int>>& grid, int n, int m, int row, int column, vector<vector<int>>& dp) {
        if (row == n - 1 && column == m - 1) return grid[row][column];
        if (row >= n || column >= m) return 1e9;
        if (dp[row][column] != -1) return dp[row][column];

        int down = solve(grid, n, m, row + 1, column, dp);
        int right = solve(grid, n, m, row, column + 1, dp);

        return dp[row][column] = grid[row][column] + min(down, right);
    }
};