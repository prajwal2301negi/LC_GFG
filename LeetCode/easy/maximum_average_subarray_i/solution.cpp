// Problem: Maximum Average Subarray I
// Difficulty: easy
// Runtime: 0 ms
// Memory: 113.6 MB

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum=0;
        double maxSum=0;
        int n = nums.size();
        if(n<k){
            return -1;
        }
        for(int i=0;i<k;i++){
            maxSum+= nums[i]; 
        }

        windowSum = maxSum;

        for(int i=k;i<n;i++){
            windowSum+= nums[i] - nums[i-k];
            maxSum = max(maxSum,windowSum);
        }

        return maxSum/k;

    }
};