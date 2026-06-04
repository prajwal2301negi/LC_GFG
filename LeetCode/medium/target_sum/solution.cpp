// Problem: Target Sum
// Difficulty: medium
// Runtime: 15 ms
// Memory: 25.2 MB

class Solution {
public:
    int solve(vector<int>& nums, int idx, int currSum, int target,
              vector<vector<int>>& dp, int offset) {

        if (idx == nums.size()) {
            return (currSum == target) ? 1 : 0;
        }

        if (dp[idx][currSum + offset] != -1)
            return dp[idx][currSum + offset];

        int add = solve(nums, idx + 1, currSum + nums[idx], target, dp, offset);

        int subtract =
            solve(nums, idx + 1, currSum - nums[idx], target, dp, offset);

        return dp[idx][currSum + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (abs(target) > sum)
            return 0;

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return solve(nums, 0, 0, target, dp, sum);
    }
};