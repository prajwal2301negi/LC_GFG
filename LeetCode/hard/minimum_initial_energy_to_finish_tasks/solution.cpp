// Problem: Minimum Initial Energy to Finish Tasks
// Difficulty: hard
// Runtime: 59 ms
// Memory: 97.4 MB

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        int low = 1;
        int high = 0;

        for (int i = 0; i < n; i++)
            high += tasks[i][1];
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isEnergySatisfied(tasks, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }

    bool isEnergySatisfied(vector<vector<int>>& tasks, int currEnergy) {
        for (int i = 0; i < tasks.size(); i++) {
            int actual = tasks[i][0];
            int minimum = tasks[i][1];
            if (currEnergy < minimum)
                return false;
            currEnergy -= actual;
        }
        return true;
    }
};