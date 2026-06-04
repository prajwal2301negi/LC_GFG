// Problem: Triangle
// Difficulty: medium
// Runtime: 3 ms
// Memory: 12.5 MB

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return solve(triangle, 0,0, n, dp);
//     }

//     int solve(vector<vector<int>>& triangle, int row, int column,int n,  vector<vector<int>>& dp){
        
//         if(row == n-1) return triangle[row][column];
        
//         if(dp[row][column] != -1) return dp[row][column];

//         int down = solve(triangle, row+1, column,n, dp);
//         int diag = solve(triangle, row+1, column+1,n, dp);

//         return dp[row][column] = (triangle[row][column]+min(down, diag));
//     }
// };


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};