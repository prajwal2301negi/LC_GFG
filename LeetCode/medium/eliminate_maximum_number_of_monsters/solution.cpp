// Problem: Eliminate Maximum Number of Monsters
// Difficulty: medium
// Runtime: 30 ms
// Memory: 89.3 MB

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        int reloadTime = 1;

        vector<double> time(n);

        for(int i =0;i<n;i++){
            time[i] = (double)dist[i]/speed[i];
        }

        sort(time.begin(),time.end());

        int ans = 1;
        int timePassed = 1;

        for(int i = 1;i<n;i++){
            if(time[i]-timePassed <= 0) return ans;
            ans++;
            timePassed+=reloadTime;
        }

        return ans;
    }
};