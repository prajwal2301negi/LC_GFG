// Problem: Jump Game VII
// Difficulty: medium
// Runtime: 16 ms
// Memory: 23 MB

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // BFS
        int n = s.length();
        if (s[n - 1] != '0') return false;

        queue<int> q;
        q.push(0);
        int farthest = 0; 

        while (!q.empty()) {
            int curr = q.front(); 
            q.pop();

    
            for (int i = max(curr + minJump, farthest + 1); i <= min(curr + maxJump, n - 1); ++i) {
                if (s[i] == '0') {
                    q.push(i);
                    if (i == n - 1) return true; 
                }
            }
            farthest = max(farthest, curr + maxJump);
        }
        return false;
    }
};