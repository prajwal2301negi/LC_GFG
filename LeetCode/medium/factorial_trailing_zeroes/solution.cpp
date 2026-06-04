// Problem: Factorial Trailing Zeroes
// Difficulty: medium
// Runtime: 0 ms
// Memory: 8.2 MB

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;

        while (n > 0) {
            n /= 5;
            ans += n;
        }

        return ans;
    }
};