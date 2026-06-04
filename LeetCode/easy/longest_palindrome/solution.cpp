// Problem: Longest Palindrome
// Difficulty: easy
// Runtime: 0 ms
// Memory: 9.4 MB

#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        int length = 0;
        bool hasOdd = false;
        
        for (char c : s) {
            counts[c]++;
        }

        for (auto const& [character, count] : counts) {
            if (count % 2 == 0) {
                length += count;
            } else {
                length += (count - 1);
                hasOdd = true; 
            }
        }
        return hasOdd ? length + 1 : length;
    }
};