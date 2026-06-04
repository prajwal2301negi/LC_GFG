// Problem: Separate the Digits in an Array
// Difficulty: easy
// Runtime: 21 ms
// Memory: 59.6 MB

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        if(n == 0) return ans;

        for(int i =0;i<n;i++){
            pushDigits(ans, nums, nums[i]); 
        }

        return ans;
    }

    void pushDigits(vector<int>& ans, vector<int> nums, int digit){
        int n = ans.size();
        while(digit>0){
            int unitDigit = digit%10;
            ans.push_back(unitDigit);
            digit=digit/10;
        }
        reverse(ans.begin()+n, ans.end());
    }

};