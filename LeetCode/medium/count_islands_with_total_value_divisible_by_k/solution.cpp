// Problem: Count Islands With Total Value Divisible by K
// Difficulty: medium
// Runtime: 24 ms
// Memory: 80.2 MB

class Solution {
    private:
    long dfs(vector<vector<int>> &grid,int row,int col,int R,int C){
        grid[row][col] = 0;
        long sum = 0;
        int rdiff[4] = {-1,1,0,0};
        int cdiff[4] = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int ar = row + rdiff[i];
            int ac = col + cdiff[i];
            if(ar>=0 && ar<R && ac>=0 && ac<C && grid[ar][ac] != 0){
                sum += grid[ar][ac];
                sum += dfs(grid,ar,ac,R,C);
            }
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        int R = grid.size();
        int C = grid[0].size();
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(grid[row][col] != 0){
                    long sum = grid[row][col];
                    sum += dfs(grid,row,col,R,C);
                    if(sum%k == 0) count++;
                }
            }
        }
        return count;
    }
};