// Problem: Mirror Distance of an Integer
// Difficulty: easy
// Runtime: 0 ms
// Memory: 8.5 MB

class Solution {
public:
    int mirrorDistance(int n) {
        long long rev=0;
        for(int x=n; x; x/=10){
            rev=10*rev+x%10;
        }
        rev-=n;
        return rev>=0?rev:-rev;
    }
};