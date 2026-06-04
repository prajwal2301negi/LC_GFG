// Problem: Isomorphic Strings
// Difficulty: easy
// Runtime: 3 ms
// Memory: 9.5 MB

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char, char> mpp;
        for(int i = 0;i<n;i++){
            if(!mpp.empty() and mpp.find(s[i]) != mpp.end()){
                if(mpp[s[i]] != t[i]) return false;
            }
            mpp[s[i]] = t[i];
        }

        unordered_map<char, char> mpp2;
        for(int i = 0;i<m;i++){
            if(!mpp2.empty() and mpp2.find(t[i]) != mpp2.end()){
                if(mpp2[t[i]] != s[i]) return false;
            }
            mpp2[t[i]] = s[i];
        }

        return true;
    }
};