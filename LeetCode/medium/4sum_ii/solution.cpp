// Problem: 4Sum II
// Difficulty: medium
// Runtime: 103 ms
// Memory: 28.1 MB

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {

        unordered_map<int, int> mp;

        for (int a : nums1) {
            for (int b : nums2) {
                mp[a + b]++;
            }
        }

        int count = 0;

        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);

                if (mp.find(target) != mp.end()) {
                    count += mp[target];
                }
            }
        }

        return count;
    }
};