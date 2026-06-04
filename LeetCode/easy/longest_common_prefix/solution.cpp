// Problem: Longest Common Prefix
// Difficulty: easy
// Runtime: 0 ms
// Memory: 12 MB

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";

        sort(strs.begin(),strs.end());

        for(int i =0;i<min(strs[0].size(),strs[n-1].size());i++){
            if(strs[0][i] == strs[n-1][i]) ans+=strs[0][i];
            else break;
        }
        return ans;
    }
};