// Problem: Equal Sum Grid Partition I
// Difficulty: medium
// Runtime: 1 ms
// Memory: 130.3 MB

class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<ll> rowSum(m, 0); // store Rowwise sum
        vector<ll> colSum(n, 0);  // store col wise sum

        ll total = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
                //row = i
                rowSum[i] += grid[i][j];
                //col = j
                colSum[j] += grid[i][j];
            }
        }

        if(total % 2 != 0) {
            return false;
        }

        //Horizontal split  -> chscking row sum
        ll upper = 0;
        for(int i = 0; i < m-1; i++) {
            upper += rowSum[i];
            if(upper == total/2) {
                return true;
            }
        }

        //Vertical split  -> checking col sum
        ll left = 0;
        for(int j = 0; j < n-1; j++) {
            left += colSum[j];
            if(left == total/2) {
                return true;
            }
        }

        return false;

    }
};
