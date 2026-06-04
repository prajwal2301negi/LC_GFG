// Problem: Jump Game V
// Difficulty: hard
// Runtime: 1525 ms
// Memory: 81.2 MB

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> max_visits(n, 1); 

        for (int i = 0; i < n; ++i) {
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int current = q.front();
                q.pop();


                for (int x = 1; x <= d; ++x) {
                    if (current + x < n && arr[current] > arr[current + x]) {
                        if (max_visits[current + x] < max_visits[current] + 1) {
                            max_visits[current + x] = max_visits[current] + 1;
                            q.push(current + x); 
                        }
                    } else {
                        break; 
                    }
                }

                for (int x = 1; x <= d; ++x) {
                    if (current - x >= 0 && arr[current] > arr[current - x]) {
                        if (max_visits[current - x] < max_visits[current] + 1) {
                            max_visits[current - x] = max_visits[current] + 1;
                            q.push(current - x); 
                        }
                    } else {
                        break; 
                    }
                }
            }
        }

        return *max_element(max_visits.begin(), max_visits.end());
    }
};