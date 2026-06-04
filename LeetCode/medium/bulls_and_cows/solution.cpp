// Problem: Bulls and Cows
// Difficulty: medium
// Runtime: 2 ms
// Memory: 9.2 MB

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        string ans = "";

        unordered_map<char, int> mpp;
        int bull = 0;
        for(int i = 0;i<n;i++){
            if(secret[i] == guess[i]) bull++;
            else mpp[secret[i]]++;
        }

        int cow = 0;

        for(int i = 0;i<n;i++){
            if(secret[i] != guess[i]){
                if(mpp.find(guess[i]) != mpp.end()){
                    if(mpp[guess[i]] >0){
                        cow++;
                        mpp[guess[i]]--;
                    }
                }
            }
        }

        ans+=to_string(bull);
        ans+='A';
        ans+=to_string(cow);
        ans+='B';

        return ans;
    }
};