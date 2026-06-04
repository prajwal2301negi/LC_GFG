// Problem: Find Unique Binary String
// Difficulty: medium
// Runtime: 0 ms
// Memory: 12.5 MB

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";

        for(int i = 0;i<n;i++){
            char ch = nums[i][i];
            if(ch == '0') ans+='1';
            else ans+='0';
        }
        return ans;
    }
};