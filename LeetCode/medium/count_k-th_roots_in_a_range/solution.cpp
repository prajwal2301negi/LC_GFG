// Problem: Count K-th Roots in a Range
// Difficulty: medium
// Runtime: 0 ms
// Memory: 8.9 MB

class Solution {
public:
    int countKthRoots(int l, int r, int k) {

        if (k == 1) {
            return r - l + 1;
        }

        double higherBound = ceil(pow(r, 1.0 / k));

        double lowerBound = 0;
        if(l == 0) lowerBound = 0;
        else lowerBound = floor(pow(l, 1.0 / k));

        int ans = 0;

        int start = max(0, (int)lowerBound - 1); // prevent negative values

        for(int i = start; i<=higherBound+1;i++){
            long long product = 1;
            for(int j = 0;j<k;j++){
                if(i>0 and product>r) break;
                product*=i;
            }
            if(product>= l and product<=r) ans++;
        }
        return ans;

    }
};