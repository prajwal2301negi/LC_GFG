// Problem: Palindromic Substrings
// Difficulty: medium
// Runtime: 3 ms
// Memory: 8.6 MB

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            // Odd length palindromes (center is at index i)
            ans += expandFromCenter(s, i, i);
            
            // Even length palindromes (center is between i and i+1)
            ans += expandFromCenter(s, i, i + 1);
        }
        
        return ans;
    }

private:
    int expandFromCenter(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};