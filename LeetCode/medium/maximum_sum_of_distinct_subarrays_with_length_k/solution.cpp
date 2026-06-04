// Problem: Maximum Sum of Distinct Subarrays With Length K
// Difficulty: medium
// Runtime: 114 ms
// Memory: 99.9 MB

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long sum = 0;
        long long ans = 0;

        int i = 0;
        int j = 0;

        unordered_map<int, int> mpp;

        while (j < n) {
            if (mpp.find(nums[j]) != mpp.end()) {
                int duplicate_idx = mpp[nums[j]];
                while (i <= duplicate_idx) {
                    sum -= nums[i];
                    mpp.erase(nums[i]);
                    i++;
                }
            }

            sum += nums[j];
            mpp[nums[j]] = j;
            if (j - i + 1 == k) {
                ans = max(sum, ans);
                sum -= nums[i];
                mpp.erase(nums[i]);
                i++;
            }
            j++;
        }

        return ans;
    }
};