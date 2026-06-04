// Problem: Check Adjacent Digit Differences
// Difficulty: easy
// Runtime: 0 ms
// Memory: 8.6 MB

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        int k = 2;

        for(int i = 1;i<n;i++){
            if(abs(s[i-1] - s[i]) > k) return false;
        }
        return true;
    }
};