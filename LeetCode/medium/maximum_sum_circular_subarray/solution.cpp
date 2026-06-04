// Problem: Maximum Sum Circular Subarray
// Difficulty: medium
// Runtime: 4 ms
// Memory: 43.6 MB

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int totSum = 0;

        int currMax = 0, maxSum = nums[0];
        int currMin = 0, minSum = nums[0];

        for (int x : nums) {
            totSum += x;

            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);
        }

        if (maxSum < 0)
            return maxSum;

        return max(totSum-minSum, maxSum);

    }
};