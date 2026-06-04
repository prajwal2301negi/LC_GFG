// Problem: Limit Occurrences in Sorted Array
// Difficulty: easy
// Runtime: 0 ms
// Memory: 33.6 MB

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for(int num: nums){
            if(ans.size()<k || ans[ans.size()-k] != num) ans.push_back(num);
        }

        return ans;
    }
};