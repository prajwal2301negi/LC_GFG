// Problem: Longest Substring Without Repeating Characters
// Difficulty: medium
// Runtime: 8 ms
// Memory: 12 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;

        unordered_map<char, int> mpp;

        int left = 0;
        int right = 0;
        int ans = 0;
        int len = 0;

        while(right<n){
            if(mpp.find(s[right]) != mpp.end() && mpp[s[right]] >= left){
                left = mpp[s[right]];
                len = right-left;
                mpp[s[right]] = right;
                left = left+1;
            }
            else{
                mpp[s[right]] = right;
                len++;
            }
            ans = max(len,ans);
            right++;
        }
        return ans;
    }
};