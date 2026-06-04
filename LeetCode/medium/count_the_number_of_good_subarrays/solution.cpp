// Problem: Count the Number of Good Subarrays
// Difficulty: medium
// Runtime: 79 ms
// Memory: 79.1 MB

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;
        if(k == 1 and n==2){
            if(nums[0] == nums[1]) return 1;
            return 0;
        }

        unordered_map<int,int> mpp;
        int pairs = 0;

        long long ans = 0;

        int i = 0;
        int j = 0;

        while(j<n){
            pairs+=mpp[nums[j]];
            mpp[nums[j]]++;

            while(pairs >= k){
                ans+=(n-j);
                mpp[nums[i]]--;
                pairs-=mpp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};