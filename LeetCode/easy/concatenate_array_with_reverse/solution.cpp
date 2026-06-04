// Problem: Concatenate Array With Reverse
// Difficulty: easy
// Runtime: 3 ms
// Memory: 30.1 MB

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n, 0);
        if(n == 0) return ans;
        if(n == 1){
            ans[0]=(nums[0]);
            ans[1] = (nums[0]);
            return ans;
        }
        for(int i =0;i<n;i++){
            ans[i] = nums[i];
        }
        int j=0;
        for(int i =n-1;i>=0;i--){
            ans[n+j] = nums[i];
            j++;
        }
        return ans;
    }
};