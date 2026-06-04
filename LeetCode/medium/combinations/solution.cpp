// Problem: Combinations
// Difficulty: medium
// Runtime: 37 ms
// Memory: 62.6 MB

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> ans;
        solve(1, n, k, result, ans);
        return result;
    }

    void solve(int start, int n, int k, vector<vector<int>>& result, vector<int> &ans){
        if(k == 0){
            result.push_back(ans);
            return;
        }

        if(start>n) return;

        for(int i =start;i<=n;i++){
            ans.push_back(i);
            solve(i+1, n, k-1, result, ans);
            ans.pop_back();
        }
        
    }
};