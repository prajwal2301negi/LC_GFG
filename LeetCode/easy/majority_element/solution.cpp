// Problem: Majority Element
// Difficulty: easy
// Runtime: 0 ms
// Memory: 28 MB

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int maj = nums[0];
        int occ = 1;

        for(int i =1;i<n;i++){
            if(occ == 0){
                occ = 1;
                maj = nums[i];
            }
            else if(maj == nums[i]) occ++;
            else occ--;
        }
        // int ans = 0;
        // for(int i =0;i<n;i++){
        //     if(maj == nums[i]) ans++;
        // }
        // if(ans > n/2) return maj;
        // return -1;
        return maj;
    }
};