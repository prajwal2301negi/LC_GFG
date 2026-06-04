// Problem: Rotate String
// Difficulty: easy
// Runtime: 0 ms
// Memory: 8.1 MB

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        int rotCnt = 0;
        while(rotCnt<n){
            rotateString(s, n);
            if(s == goal) return true;
            rotCnt++;
        }
        return false;
    }

    void rotateString(string &s, int n){
        char temp = s[0];
        int i =1;
        while(i<n){
            s[i-1] = s[i];
            i++;
        }
        s[n-1] = temp;
    }
};