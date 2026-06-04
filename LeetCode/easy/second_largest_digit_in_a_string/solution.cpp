// Problem: Second Largest Digit in a String
// Difficulty: easy
// Runtime: 0 ms
// Memory: 10.1 MB

class Solution {
public:
    int secondHighest(string s) {
        vector<int> digits;
        for(char ch : s){
            if(isdigit(ch)){
                digits.push_back(ch-'0');
            }
        }
        int fmax = INT_MIN, smax = INT_MIN;
        for(int num : digits){
            if(num > fmax){
                smax = fmax;
                fmax = num;
            }
            else if(num > smax && num < fmax){
                smax = num;
            }
        }
        return (smax!=INT_MIN) ? smax : -1;
    }
};