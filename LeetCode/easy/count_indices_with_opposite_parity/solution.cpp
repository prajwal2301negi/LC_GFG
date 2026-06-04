// Problem: Count Indices With Opposite Parity
// Difficulty: easy
// Runtime: 3 ms
// Memory: 33.3 MB

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        if(n==1){
            return ans;
        }

        vector<int> oddNum(n,0);
        vector<int> evenNum(n,0);

        int evenCnt = 0;
        int oddCnt = 0;

        for(int i =n-1;i>=0;i--){
            if(nums[i]%2 == 0){
                evenCnt++;
                evenNum[i] = evenCnt;
                oddNum[i] = oddCnt;
            }
            else{
                oddCnt++;
                oddNum[i] = oddCnt;
                evenNum[i] = evenCnt;
            }
        }

        for(int i =0;i<n;i++){
            if(nums[i]%2 != 0){
                ans[i] = evenNum[i];
            }
            else ans[i] = oddNum[i];
        }

        return ans;
    }
};