// Problem: Earliest Finish Time for Land and Water Rides II
// Difficulty: medium
// Runtime: 0 ms
// Memory: 238 MB

class Solution {
public:
    int calFinishTime(vector<int>& ls,vector<int>& ld,vector<int>& ws,vector<int>& wd) {

        int mini = INT_MAX;

        for (int i = 0; i < ls.size(); i++) {
            mini = min(mini, ls[i] + ld[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < ws.size(); i++) {
            ans = min(ans,max(mini, ws[i]) + wd[i]);
        }

        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            calFinishTime(landStartTime,landDuration,waterStartTime,waterDuration),
            calFinishTime(waterStartTime,waterDuration,landStartTime,landDuration)
        );
    }
};