// Problem: Shortest Common Supersequence 
// Difficulty: hard
// Runtime: 27 ms
// Memory: 26.8 MB

class Solution {
public:

    // MLE -> 47/50
    // string shortestCommonSupersequence(string str1, string str2) {
    //     int n = str1.size();
    //     int m = str2.size();

    //     if (n == 0)
    //         return str2;
    //     if (m == 0)
    //         return str1;

    //     vector<vector<string>> dp(n + 1, vector<string>(m + 1, "-1"));
    //     string subt = "";
    //     return solve(str1, str2, 0, 0, dp);
    // }

    // string solve(string& str1, string& str2, int idx1, int idx2,
    //              vector<vector<string>>& dp) {
    //     if (idx1 == str1.size())
    //         return str2.substr(idx2);
    //     if (idx2 == str2.size())
    //         return str1.substr(idx1);

    //     if (dp[idx1][idx2] != "-1")
    //         return dp[idx1][idx2];

    //     if (str1[idx1] == str2[idx2]) {
    //         return dp[idx1][idx2] = str1[idx1] + solve(str1, str2, idx1 + 1, idx2 + 1, dp);
    //     } else {
    //         string pick1 = str1[idx1] + solve(str1, str2, idx1 + 1, idx2, dp);
    //         string pick2 = str2[idx2] + solve(str1, str2, idx1, idx2 + 1, dp);

    //         if (pick1.size() < pick2.size()) {
    //             return dp[idx1][idx2] = pick1;
    //         } else {
    //             return dp[idx1][idx2] = pick2;
    //         }
    //     }
    // }
    
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            } else {
                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }

};