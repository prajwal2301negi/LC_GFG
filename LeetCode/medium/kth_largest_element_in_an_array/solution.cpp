// Problem: Kth Largest Element in an Array
// Difficulty: medium
// Runtime: 41 ms
// Memory: 59.3 MB

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int target = k-1;

        while(left<=right){
            int pivotIndex = solve(nums, left, right);

            if(pivotIndex == target) return nums[pivotIndex];
            else if(pivotIndex > target) right = pivotIndex-1;
            else left = pivotIndex+1;
        }
        return -1;
    }

    int solve(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int i = left+1;
        int j = right;

        while(i<=j){
            if(nums[i]<pivot and nums[j]>pivot){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(i<=j and nums[i]>=pivot) i++;
            if(i<=j and nums[j]<=pivot) j--;
        }
        swap(nums[left], nums[j]);
        return j;
    }
};