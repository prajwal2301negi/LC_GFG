// Problem: Largest Odd Number in String
// Difficulty: easy
// Runtime: 0 ms
// Memory: 17.9 MB

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        
        int maxi = 0;
        string ans = "";
        int digit = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1); // maximum as starting from 0 to i
            }
        }
        return "";
    }
};