// Problem: Reverse String
// Difficulty: easy
// Runtime: 0 ms
// Memory: 27.1 MB

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};