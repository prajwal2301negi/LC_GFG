// Problem: Find and Replace Pattern
// Difficulty: medium
// Runtime: 5 ms
// Memory: 11.7 MB

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        vector<string> ans;
        for(int i = 0;i<n;i++){
            if(match(words[i], pattern)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }

    bool match(string& a, string b){
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;

        for(int i = 0 ; i<a.size();i++){
            if(mp1.count(a[i]) && mp1[a[i]] != b[i]) return false;
            if(mp2.count(b[i]) && mp2[b[i]] != a[i]) return false;
            mp1[a[i]] = b[i];
            mp2[b[i]] = a[i];
        }
        return true;
    }
};