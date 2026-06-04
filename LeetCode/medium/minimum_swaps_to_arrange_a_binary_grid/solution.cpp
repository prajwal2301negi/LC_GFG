// Problem: Minimum Swaps to Arrange a Binary Grid
// Difficulty: medium
// Runtime: 0 ms
// Memory: 30 MB

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();  // n==m

        vector<int> endZeros(n, 0); // store the zeroes from end in respective rows

        for (int i = 0; i < n; i++) {
            int j = n - 1; // calculating zeroes from end
            int count = 0;
            while (j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }
            endZeros[i] = count; // store zeroes count in vector
        }

        int steps = 0;

        for (int i = 0; i < n; i++) {
            int need = n - i - 1;  // no of zeroes needed(formula)
            int j = i;
            while (j < n && endZeros[j] < need) {
                j++;
            }
            if (j == n) {
                return -1;         // no of zeroes needed not present
            }
            steps += j - i;
            while (j > i) {
                swap(endZeros[j], endZeros[j - 1]);   // swapping rows as alternate rows shoudl be swapped
                j--;
            }
        }

        return steps;
    }
};