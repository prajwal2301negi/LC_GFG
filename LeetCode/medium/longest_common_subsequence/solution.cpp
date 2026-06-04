// Problem: Longest Common Subsequence
// Difficulty: medium
// Runtime: 46 ms
// Memory: 27.5 MB

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if (n == 0 || m == 0) return 0;

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(text1, text2, n, m, 0, 0, dp);
    }
    int solve(string& text1, string& text2, int n, int m, int idx1, int idx2, vector<vector<int>>& dp){

        if(idx1== n || idx2==m) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        int sameChar = 0;
        int diffChar = 0;

        if(text1[idx1] == text2[idx2]) sameChar = 1+solve(text1, text2, n, m, idx1+1, idx2+1, dp);
        else if(text1[idx1] != text2[idx2]) diffChar = max(solve(text1, text2, n, m, idx1+1, idx2, dp), solve(text1, text2, n, m, idx1, idx2+1, dp));

        return dp[idx1][idx2] = max(sameChar, diffChar);
    }
};