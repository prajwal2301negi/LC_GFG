// Problem: Partition Equal Subset Sum
// Difficulty: medium
// Runtime: 198 ms
// Memory: 205.7 MB

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = totalSum(nums);
        if(target%2 != 0) return false;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(nums, n, 0, target/2, dp);
    }

    bool solve(vector<int>& nums, int n, int idx, int target, vector<vector<int>>& dp){
        if(idx>=n){
            // if(target == 0) return true;
            return false;
        }

        if(target == 0) return true;
        if(dp[idx][target] != -1) return dp[idx][target];

        bool take = false;
        if(target>=nums[idx]) take = solve(nums, n, idx+1, target-nums[idx], dp);
        bool notTake = solve(nums, n, idx+1, target, dp);

        return dp[idx][target] = take | notTake;
    }

    int totalSum(vector<int>& nums){
        int n = nums.size();
        int totSum = 0;
        for(int i = 0;i<n;i++) totSum+=nums[i];
        return totSum;
    }
};