// Problem: Edit Distance
// Difficulty: medium
// Runtime: 7 ms
// Memory: 14.5 MB

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n == 0) return m;
        if(m == 0) return n;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, 0, 0, n, m, dp);
    }

    int solve(const string &word1, const string &word2, int idx1, int idx2, int n, int m, vector<vector<int>>& dp) {
        
        if(idx1 == n) return m - idx2; 
        if(idx2 == m) return n - idx1; 

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        int take = 1e9;
        int notTake = 1e9;

        if(word1[idx1] == word2[idx2]) {
            take = solve(word1, word2, idx1 + 1, idx2 + 1, n, m, dp);

        } else {
            int insertOp = solve(word1, word2, idx1, idx2 + 1, n, m, dp);
            int deleteOp = solve(word1, word2, idx1 + 1, idx2, n, m, dp);
            int replaceOp = solve(word1, word2, idx1 + 1, idx2 + 1, n, m, dp);

            notTake = 1 + min({insertOp, deleteOp, replaceOp});
        }

        return dp[idx1][idx2] = min(take, notTake);
    }
};