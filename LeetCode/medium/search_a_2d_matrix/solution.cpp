// Problem: Search a 2D Matrix
// Difficulty: medium
// Runtime: 0 ms
// Memory: 13.4 MB

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m-1;

        while(row>=0 and row<n and col>=0 and col<m){
            int num = matrix[row][col];
            if(num == target) return true;
            else if(num>target) col--;
            else if(num<target) row++;

        }
        return false;
    }
};