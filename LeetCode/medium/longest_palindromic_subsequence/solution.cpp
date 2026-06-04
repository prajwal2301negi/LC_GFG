// Problem: Longest Palindromic Subsequence
// Difficulty: medium
// Runtime: 87 ms
// Memory: 76 MB

class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp,
              int n) {
        if (i == n || j == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int take = 0;
        int notTake = 0;
        if (s1[i] == s2[j]) {
            take = 1 + solve(i + 1, j + 1, s1, s2, dp, n);
        } else {
            notTake = max(solve(i , j + 1, s1, s2, dp, n),
                          solve(i + 1, j , s1, s2, dp, n));
        }

        return dp[i][j] = max(take, notTake);
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, 0, s, s2, dp, n);
    }
};
