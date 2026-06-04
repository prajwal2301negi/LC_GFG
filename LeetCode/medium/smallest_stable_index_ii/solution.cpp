// Problem: Smallest Stable Index II
// Difficulty: medium
// Runtime: 12 ms
// Memory: 202.7 MB

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 and k>=0) return 0;

        vector<int> minValue(n, 0);

        minValue[n-1] = nums[n-1];
        int mini = nums[n-1];
        for(int i = n-2;i>=0;i--){
            mini = min(mini, nums[i]);
            minValue[i] = min(nums[i],mini);
        }

        int maxi = nums[0];
        for(int i =0;i<n;i++){
            maxi = max(maxi,nums[i]);
            if(maxi - minValue[i] <= k) return i;
        }
        return -1;
    }
};