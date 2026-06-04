// Problem: Digit Frequency Score
// Difficulty: easy
// Runtime: 0 ms
// Memory: 9.3 MB

class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> mpp;
        int num = n;
        while(num>0){
            int unitDigit = num%10;
            mpp[unitDigit]++;
            num = num/10;
        }

        int sum =0;
        for(auto x: mpp){
            sum+=(x.first*x.second);
        }
        return sum;
    }

};