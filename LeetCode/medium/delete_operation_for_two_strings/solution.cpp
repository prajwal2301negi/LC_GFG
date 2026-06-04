// Problem: Delete Operation for Two Strings
// Difficulty: medium
// Runtime: 21 ms
// Memory: 16.7 MB

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        if(n == 0) return m;
        if(m == 0) return n;
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return n + m - 2 * solve(word1, word2, 0, 0, dp);
    }
    

    int solve(string &word1, string &word2, int i, int j, vector<vector<int>>& dp) {
        if(i == word1.size() || j == word2.size()) return 0;
         
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = 1+solve(word1, word2, i+1, j+1, dp);
        }

        else return dp[i][j] =  max(solve(word1, word2, i+1, j, dp), solve(word1, word2, i, j+1, dp));
        
            
    }
        
    


};