// Problem: Find the Score of All Prefixes of an Array
// Difficulty: medium
// Runtime: 2 ms
// Memory: 61.6 MB

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> converted(n);

        int maxi = nums[0];
        converted[0] = nums[0] + maxi;

        for (int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i]);
            converted[i] = nums[i] + maxi;
        }

        vector<long long> ans(n);
        ans[0] = converted[0];

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + converted[i];
        }


        return ans;

    }
};