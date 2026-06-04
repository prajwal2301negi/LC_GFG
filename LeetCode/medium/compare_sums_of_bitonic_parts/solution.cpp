// Problem: Compare Sums of Bitonic Parts
// Difficulty: medium
// Runtime: 0 ms
// Memory: 125.6 MB

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        long long sum = nums[0];
        for(int i =1;i<n;i++){
            if(nums[i-1]<nums[i] and nums[i]>nums[i+1]) sum-=nums[i];
            if(nums[i-1]<nums[i]) sum+=nums[i];
            else sum-=nums[i];
        }
        
        if(sum>0) return 0;
        else if(sum<0) return 1;
        return -1;


    }
};