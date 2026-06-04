// Problem: Search in Rotated Sorted Array
// Difficulty: medium
// Runtime: 0 ms
// Memory: 15.2 MB

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int s=0;
        int e=n;
        
        
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
                
            }
            if(nums[s]<=nums[mid]){
                if(nums[s]<=target and target<=nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(nums[mid]<=target and target<=nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }

            
        }
        return -1;
        
    }
};