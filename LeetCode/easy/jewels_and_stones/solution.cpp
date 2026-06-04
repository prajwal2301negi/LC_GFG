// Problem: Jewels and Stones
// Difficulty: easy
// Runtime: 1 ms
// Memory: 8.8 MB

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> m;

        for(char ch : jewels){
            m[ch] = 1;
        }

        int cnt = 0;
        for(char ch : stones){
            if(m[ch] == 1){ 
                cnt++;
            }
        }

        return cnt;
    }
};