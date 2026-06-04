// Problem: Count Commas in Range II
// Difficulty: medium
// Runtime: 0 ms
// Memory: 9 MB

class Solution {
public:
    long long countCommas(long long n) {
        long long commas=999;
        long long ans=0;
        while(n>commas){
            ans+=(n-commas);
            commas=commas*1000+999;
        }
        return ans;
    }
};