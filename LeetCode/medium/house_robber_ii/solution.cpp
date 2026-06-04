// Problem: House Robber II
// Difficulty: medium
// Runtime: 3 ms
// Memory: 10.9 MB

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);
        return max(solve(nums,0,n-1,dp1), solve(nums, 1, n,dp2));
    }

    int solve(vector<int>& nums, int startIdx, int endIdx, vector<int>& dp){
        if(startIdx>=endIdx) return 0;

        if(dp[startIdx] != -1) return dp[startIdx];
        
        int rob = nums[startIdx]+solve(nums, startIdx+2, endIdx, dp);
        int leave = solve(nums, startIdx+1, endIdx, dp);

        return dp[startIdx] = max(rob, leave);

    }

    
};