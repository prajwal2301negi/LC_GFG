// Problem: Password Strength
// Difficulty: medium
// Runtime: 24 ms
// Memory: 17.8 MB

class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> lower, upper, digit, special;

        string specialChars = "!@#$";

        for(char ch: password){
            if(islower(ch)) lower.insert(ch);
            else if(isupper(ch)) upper.insert(ch);
            else if(isdigit(ch)) digit.insert(ch);
            else if(specialChars.find(ch) != string::npos) special.insert(ch);
        }

        return lower.size()+upper.size()*2+digit.size()*3+special.size()*5;
    }
};