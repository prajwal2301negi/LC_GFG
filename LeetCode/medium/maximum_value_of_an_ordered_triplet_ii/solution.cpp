// Problem: Maximum Value of an Ordered Triplet II
// Difficulty: medium
// Runtime: 0 ms
// Memory: 98.7 MB

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
    
        vector<int> nge(n, 0);
        nge[n-1] = nums[n-1];
        int maxi = nums[n-1];
        for(int i = n-2;i>=0;i--){
            int currEle = nums[i];
            maxi = max(maxi, currEle);
            nge[i] = maxi;
        }


        vector<int> pge(n, 0);
        pge[0] = nums[0];
        maxi = nums[0];
        for(int i = 1;i<n;i++){
            int currEle = nums[i];
            maxi = max(maxi, currEle);
            pge[i] = maxi;
        }

        long long ans = 0;
        for(int i = 1;i<n-1;i++){
            int nums_i = pge[i-1];
            int nums_j = nums[i];
            int nums_k = nge[i+1];

            long long digit = (nums_i - nums_j);
            digit*=nums_k;
            ans = max(ans, digit);
        }

        return ans;
    }
};