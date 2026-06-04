// Problem: Find the Maximum Factor Score of Array
// Difficulty: medium
// Runtime: 35 ms
// Memory: 35.3 MB

class Solution {
public:
    int calculateGCD(const vector<int>& nums) {
        int gcd_val = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            gcd_val = gcd(gcd_val, nums[i]);
        }
        return gcd_val;
    }

    long long lcm(long long a, long long b) { 
        return a / gcd(a, b) * b;
    }

    long long calculateLCM(const vector<int>& nums) {
        long long ans = 1;

        for (int x : nums) {
            ans = lcm(ans, x);
        }

        return ans;
    }

    long long maxScore(vector<int>& nums) {
        int totalGCD = calculateGCD(nums);
        long long totalLCM = calculateLCM(nums);

        long long maxFactorScore = 1LL * totalGCD * totalLCM;

        for (int i = 0; i < nums.size(); ++i) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j)
                    temp.push_back(nums[j]);
            }

            if (!temp.empty()) {
                int gcd = calculateGCD(temp);
                long long lcm = calculateLCM(temp);
                maxFactorScore = max(maxFactorScore, 1LL * gcd * lcm);
            }
        }

        return maxFactorScore;
    }
};
