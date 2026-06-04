// Problem: Valid Digit Number
// Difficulty: easy
// Runtime: 0 ms
// Memory: 7.8 MB

class Solution {
public:
    bool validDigit(int n, int x) {
        bool flag = false;
        int lastDigit =0 ;
        if(n>0 and n<=9) return false;
        while(n>0){
            int unitDigit = n%10;
            if(unitDigit == x) flag = true;
            n = n/10;
            if(n>0 and n<10) lastDigit = n;
        }

        if(lastDigit != x and flag == true) return true;
        return false;
    }
};