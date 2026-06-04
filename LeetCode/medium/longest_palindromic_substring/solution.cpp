// Problem: Longest Palindromic Substring
// Difficulty: medium
// Runtime: 11 ms
// Memory: 9.3 MB

class Solution {
public:
    void expand(int start, int end, string &s, int &strt, int &maxLen){
        while(start>=0 and end<s.size() and s[start] == s[end]){
            if(maxLen<end-start+1) {
                maxLen = end-start+1;
                strt = start;
            }
            start--;
            end++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        int maxLen = 1;
        int strt = 0;

        for(int i = 0;i<n;i++){
            // odd
            expand(i,i,s, strt, maxLen);

            //even
            expand(i,i+1,s,strt,maxLen);
        }

        return s.substr(strt, maxLen) ;

       
    }
};