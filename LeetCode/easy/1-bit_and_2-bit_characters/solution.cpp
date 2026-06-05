// Problem: 1-bit and 2-bit Characters
// Difficulty: easy
// Runtime: 0 ms
// Memory: 13.2 MB

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;        
        while (i < n - 1)
            i += bits[i] + 1;

        return i == n - 1;
    }
};
