// Problem: Minimum Distance Between Three Equal Elements I
// Difficulty: easy
// Runtime: 0 ms
// Memory: 29.7 MB

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;

        for (auto &it : mp) {
            vector<int> &pos = it.second;

            if (pos.size() < 3) continue;

            for (int i = 0; i + 2 < pos.size(); i++) {
                int curr = pos[i + 2] - pos[i];
                ans = min(ans, curr);
            }
        }

        if (ans == INT_MAX) return -1;

        return 2 * ans;  
    }
};