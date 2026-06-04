// Problem: Split a String in Balanced Strings
// Difficulty: easy
// Runtime: 0 ms
// Memory: 8.5 MB

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int length = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L')
                count++;
            else
                count--;

            if (count == 0) {
                length++;
            }
        }
        return length;
    }
};