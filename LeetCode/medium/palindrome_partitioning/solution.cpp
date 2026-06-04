// Problem: Palindrome Partitioning
// Difficulty: medium
// Runtime: 56 ms
// Memory: 80 MB

class Solution {
public:
    vector<vector<string>> result;

    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(0, s, path);
        return result;
    }

    void solve(int start, string &s, vector<string> &path) {
        if(start == s.size()) {
            result.push_back(path);
            return;
        }

        for(int i = start; i < s.size(); i++) {
            if(isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                solve(i + 1, s, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};