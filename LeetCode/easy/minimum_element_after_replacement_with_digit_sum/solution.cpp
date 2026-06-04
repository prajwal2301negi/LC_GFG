// Problem: Minimum Element After Replacement With Digit Sum
// Difficulty: easy
// Runtime: 0 ms
// Memory: 27.8 MB

class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();

        int mini = 1e9;

        for(int i =0;i<n;i++){
            mini = min(mini, sumNum(nums[i]));
        }
        return mini;
    }

    int sumNum(int num){
        int sum = 0;
        while(num>0){
            int unitDigit = num%10;
            sum+=unitDigit;
            num = num/10;
        }
        return sum;
    }
};