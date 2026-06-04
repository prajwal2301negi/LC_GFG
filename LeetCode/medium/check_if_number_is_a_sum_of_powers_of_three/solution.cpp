// Problem: Check if Number is a Sum of Powers of Three
// Difficulty: medium
// Runtime: 0 ms
// Memory: 7.8 MB

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int num = 3;
        while(n>0){
            if(n%3 >= (num-1)) return false;
            n=n/3;
        }
        return true;
    }
};