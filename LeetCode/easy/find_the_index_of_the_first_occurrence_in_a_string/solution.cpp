// Problem: Find the Index of the First Occurrence in a String
// Difficulty: easy
// Runtime: 0 ms
// Memory: 9.3 MB

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.length();
        int m = needle.length();

        for(int i = 0; i <= n - m; i++){
            if(haystack.substr(i, m) == needle){
                return i;
            }
        }

        return -1;
    }
};