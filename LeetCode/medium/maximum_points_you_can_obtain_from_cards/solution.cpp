// Problem: Maximum Points You Can Obtain from Cards
// Difficulty: medium
// Runtime: 0 ms
// Memory: 46.2 MB

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(k>n) return 0;
        if(k == n) return sumArr(cardPoints);
        int suffixSum = 0;
        

        for(int i = n-1;i>(n-k-1);i--){
            suffixSum+=cardPoints[i];
        }

        int lastSum = suffixSum;

        for(int i = 0;i<k;i++){
            suffixSum = suffixSum + cardPoints[i] - cardPoints[n - k + i];
            lastSum = max(lastSum, suffixSum);
        }

        return lastSum;

        
    }
    int sumArr(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        return sum;
    }
};