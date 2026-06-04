// Problem: Greatest Common Divisor of Strings
// Difficulty: easy
// Runtime: 0 ms
// Memory: 9.8 MB

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        if(str1+str2 != str2+str1) return "";

        // if(n>m){
        //     return str1.substr(0, (n/m));
        // }
        // return str2.substr(0, (m/n));

        return str1.substr(0, gcd(n,m));
    }
};