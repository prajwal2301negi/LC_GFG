// Problem: Check if Array Is Sorted and Rotated
// Difficulty: easy
// Runtime: 0 ms
// Memory: 11.3 MB

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int minPos = getPivotIndex(nums);
        for(int i = minPos;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        for(int i = minPos-1;i>0;i--){
            if(nums[i-1] > nums[i]) return false;
        }

        if(minPos > 0 && nums[n-1] > nums[0]) {
            return false;
        }

        return true;
    }

    int getPivotIndex(vector<int>& nums){
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                return i + 1; 
            }
        }
        return 0;
    }
};