// Problem: Jump Game IV
// Difficulty: hard
// Runtime: 76 ms
// Memory: 75 MB

class Solution {
public:
    int minJumps(vector<int>& arr) {
        // BFS -> use for finding shortest path
        int n = arr.size();
        if (n == 1)
            return 0;
        unordered_map<int, vector<int>> mpp;
        queue<int> q;
        vector<bool> visited(n, false);
        int i = 0;
        q.push(i); // currIndex
        visited[i] = true;

        for (int j = 0; j < n; j++) {
            mpp[arr[j]].push_back(j);
        }
        

        int steps = 0;

        while (!q.empty()) {
            // int curr = q.front();
            // q.pop();

            // if(i == n-1){
            //     return steps;
            // }
            // // option1
            // if(i+1<n and vis[i+1]!=1){
            //     i = i+1;
            // }
            // //option2
            // if(i-1>=0 and vis[i-1]!=1){
            //     i = i-1
            // }
            // //option3
            // if(mpp.find(arr[i])!=mpp.end()){
            //     q.push(arr[i].second(k));
            //     k++;
            //     i = k;
            // }
            // for(int op=1;op<=3;op++){
            //     q.push(i);
            // }

            int size = q.size();

            // Process all indices at the current BFS level
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                // Check if we reached the last index
                if (curr == n - 1)
                    return steps;

                // Option 1: Jump to the next index
                if (curr + 1 < n && !visited[curr + 1]) {
                    q.push(curr + 1);
                    visited[curr + 1] = true;
                }

                // Option 2: Jump to the previous index
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    q.push(curr - 1);
                    visited[curr - 1] = true;
                }

                // Option 3: Jump to any other index with the same value
                if (mpp.count(arr[curr])) {
                    for (int next : mpp[arr[curr]]) {
                        if (!visited[next]) {
                            q.push(next);
                            visited[next] = true;
                        }
                    }
                    // Clear the list to avoid redundant processing
                    mpp.erase(arr[curr]);
                }
            }

            steps++; // Increment steps after proce
        }

        return -1;
    }
};