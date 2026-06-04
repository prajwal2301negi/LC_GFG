// Problem: Longest String Chain
// Difficulty: medium
// Runtime: 163 ms
// Memory: 105.9 MB

class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.length() < s2.length();
    }

    bool checkPossible(string &s1, string &s2){
        if(s1.size() != s2.size() + 1){
            return false;
        }
        int first = 0;
        int second = 0;
        int count = 0;
        while(first<s1.size()){
            if(second < s2.size() and s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        return (first == s1.size() and second == s2.size());
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
      
        sort(words.begin(), words.end(), comp);
        return solve(words, 0, -1, dp);
    }
    
    int solve(vector<string>& words, int idx, int prev_idx, vector<vector<int>>& dp) {
        if (idx == words.size()) 
            return 0;

        if (dp[idx][prev_idx + 1] != -1) 
            return dp[idx][prev_idx + 1];

        int take = 0;

        if (prev_idx == -1 || checkPossible(words[idx], words[prev_idx])) {
            take = 1 + solve(words, idx + 1, idx, dp); 
        }

        int skip = solve(words, idx + 1, prev_idx, dp);

        return dp[idx][prev_idx + 1] = max(take, skip);
    }
};