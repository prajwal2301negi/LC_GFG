// Problem: Valid Anagram
// Difficulty: easy
// Runtime: 0 ms
// Memory: 9.7 MB

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n!=m) return false;

        unordered_map<char, int> mpp;
        for(int i = 0;i<n;i++){
            mpp[s[i]]++;
        }

        for(int i =0;i<n;i++){
            if(mpp.find(t[i]) != mpp.end()){
                mpp[t[i]]--;
            }
            else if(mpp.find(t[i]) == mpp.end()){
                return false;
            }
        }
        
        for(auto i:mpp){
            if(i.second != 0) return false;
        }
        return true;

    }
};