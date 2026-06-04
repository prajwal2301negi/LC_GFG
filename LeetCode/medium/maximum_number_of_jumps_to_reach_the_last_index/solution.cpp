// Problem: Maximum Number of Jumps to Reach the Last Index
// Difficulty: medium
// Runtime: 31 ms
// Memory: 68.5 MB

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n, -1);
        int result = solve(nums, target, n, 0, dp);
        return result < 0 ? -1 : result;
    }

    int solve(vector<int>& nums, int target, int n, int idx, vector<int>& dp){
        if(idx == n-1) return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = INT_MIN;

        for(int i =idx+1;i<n;i++){
            if(abs(nums[i]-nums[idx])<=target) {
                int jump = 1+solve(nums, target, n, i, dp);
                ans = max(jump, ans);
            }
        }

        return dp[idx] = ans;
    }
};