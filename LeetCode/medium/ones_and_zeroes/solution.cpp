// Problem: Ones and Zeroes
// Difficulty: medium
// Runtime: 99 ms
// Memory: 93.8 MB

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<pair<int, int>> nums;

        for (int i = 0; i < s; i++) {
            int count0 = 0;
            int count1 = 0;

            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    count0++;
                else if (strs[i][j] == '1')
                    count1++;
            }
            nums.push_back({count0, count1});
        }

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(s+1,-1)));

        return solve(nums, n, m, 0, dp);
    }

    int solve(vector<pair<int, int>>& nums, int count1, int count0, int idx, vector<vector<vector<int>>>& dp) {
        if (idx == nums.size())
            return 0;

        if(dp[count1][count0][idx] != -1) return dp[count1][count0][idx];

        int take = 0;
        if (count1 >= nums[idx].second and count0 >= nums[idx].first)
            take = 1 + solve(nums, count1 - nums[idx].second,
                             count0 - nums[idx].first, idx + 1, dp);
        int skip = solve(nums, count1, count0, idx + 1, dp);

        return dp[count1][count0][idx] = max(take, skip);
    }
};