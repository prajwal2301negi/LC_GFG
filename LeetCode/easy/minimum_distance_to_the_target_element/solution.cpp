// Problem: Minimum Distance to the Target Element
// Difficulty: easy
// Runtime: 0 ms
// Memory: 13.1 MB

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
                result = min(result,abs(i-start));
        }
        return result;
    }
};