// Problem: Game of Life
// Difficulty: medium
// Runtime: 0 ms
// Memory: 9.5 MB

class Solution {
public:
    bool isSafe(int x, int y, int R, int C) {
        return x >= 0 && x < R && y >= 0 && y < C;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int R = board.size();
        int C = board[0].size();

        vector<vector<int>> copyBoard = board;

        vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {

                int liveCounts = 0;

                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (isSafe(nx, ny, R, C) &&
                        copyBoard[nx][ny] == 1) {
                        liveCounts++;
                    }
                }

                if (copyBoard[i][j] == 0 && liveCounts == 3) {
                    board[i][j] = 1;
                }

                if (copyBoard[i][j] == 1 &&
                    (liveCounts < 2 || liveCounts > 3)) {
                    board[i][j] = 0;
                }
            }
        }
    }
};