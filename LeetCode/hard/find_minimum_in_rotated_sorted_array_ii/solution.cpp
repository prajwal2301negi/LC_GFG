// Problem: Find Minimum in Rotated Sorted Array II
// Difficulty: hard
// Runtime: 0 ms
// Memory: 16.2 MB

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int ans=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==nums[s] and nums[mid]==nums[e]){
                ans=min(ans,nums[s]);
                s++;
                e--;
                continue;
            }
            
            if(nums[mid]>=nums[s]){
                ans=min(ans,nums[s]);
                s=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                e=mid-1;
            }
        }
        return ans;
    }
};