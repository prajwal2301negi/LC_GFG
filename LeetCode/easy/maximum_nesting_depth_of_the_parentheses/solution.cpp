// Problem: Maximum Nesting Depth of the Parentheses
// Difficulty: easy
// Runtime: 0 ms
// Memory: 8.3 MB

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        int cnt = 0;
        int maxi = 0;

        for(int i =0;i<n;i++){
            if(s[i] == '(') cnt++;
            if(maxi<cnt) maxi = cnt;
            else if(s[i] == ')') cnt--;
        }
        return maxi;

    }
};