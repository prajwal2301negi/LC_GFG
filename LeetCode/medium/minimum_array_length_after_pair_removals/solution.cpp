// Problem: Minimum Array Length After Pair Removals
// Difficulty: medium
// Runtime: 0 ms
// Memory: 153.2 MB

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = (n + 1) / 2;

        int pairs = 0;

        while (i < n / 2 && j < n) {
            if (nums[i] < nums[j]) {
                pairs++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return n - 2 * pairs;
    }
};