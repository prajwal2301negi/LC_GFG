// Problem: Valid Elements in an Array
// Difficulty: easy
// Runtime: 3 ms
// Memory: 32.8 MB

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return nums;
        vector<int> ans;
        ans.push_back(nums[0]);
        
        vector<int>prefixSum(n,0);
        vector<int>suffixSum(n,0);
        
        prefixSum[0] = nums[0];
        int maxi = nums[0];
        for(int i =1;i<n;i++){
            if(maxi<nums[i]) {
                prefixSum[i] = nums[i];
                maxi = nums[i];
            }
            else prefixSum[i] = maxi;
        }
        
        suffixSum[n-1] = nums[n-1];
        maxi = nums[n-1];
        for(int i =n-2;i>=0;i--){
            if(maxi<nums[i]) {
                suffixSum[i] = nums[i];
                maxi = nums[i];
            }
            else suffixSum[i] = maxi;
        }
        
        for(int i =1;i<n-1;i++){
            if(nums[i]>suffixSum[i+1] || nums[i]>prefixSum[i-1]){
                ans.push_back(nums[i]);
            }
        }
        
        ans.push_back(nums[n-1]);
        
        return ans;
        
    }
};