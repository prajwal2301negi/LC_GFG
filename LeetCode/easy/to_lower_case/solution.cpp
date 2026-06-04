// Problem: To Lower Case
// Difficulty: easy
// Runtime: 0 ms
// Memory: 8.3 MB

class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
          ans+=tolower(s[i]);
        }
        return ans;
    }
};