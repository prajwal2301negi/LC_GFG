// Problem: Minimum Moves to Make Array Complementary
// Difficulty: medium
// Runtime: 8 ms
// Memory: 93.3 MB

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];
        
            int low = min(a, b);
            int high = max(a, b);
            
            // Case 1: Range [2, 2 * limit] initially takes 2 moves
            diff[2] += 2;
            
            // Case 2: Range [low + 1, high + limit] takes 1 move
            diff[low + 1] -= 1;
            
            // Case 3: The specific sum (a + b) takes 0 moves
            diff[low + high] -= 1;
            
            // Case 4: Sums greater than (a + b) go back to 1 move
            diff[low + high + 1] += 1;
            
            // Case 5: Sums greater than (high + limit) go back to 2 moves
            diff[high + limit + 1] += 1;
        }

        int min_moves = n; 
        int current_moves = 0;
        
        for (int s = 2; s <= 2 * limit; ++s) {
            current_moves += diff[s];
            if (current_moves < min_moves) {
                min_moves = current_moves;
            }
        }

        return min_moves;
    }
};