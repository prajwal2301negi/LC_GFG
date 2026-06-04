// Problem: Jump Game III
// Difficulty: medium
// Runtime: 0 ms
// Memory: 35.4 MB

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (arr[curr] == 0) {
                return true;
            }

            int next1 = curr + arr[curr];
            int next2 = curr - arr[curr];

            if (next1 >= 0 && next1 < n && !visited[next1]) {
                q.push(next1);
                visited[next1] = true;
            }

            if (next2 >= 0 && next2 < n && !visited[next2]) {
                q.push(next2);
                visited[next2] = true;
            }
        }

        return false;
    }
};