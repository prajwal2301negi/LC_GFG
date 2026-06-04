// Problem: Destroying Asteroids
// Difficulty: medium
// Runtime: 34 ms
// Memory: 106.6 MB

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long m = mass;
        for(int i=0;i<asteroids.size();i++){
            if(m<asteroids[i]) return false;
            m += asteroids[i];
        }
        return true;
    }
};