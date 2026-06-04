// Problem: Watering Plants
// Difficulty: medium
// Runtime: 0 ms
// Memory: 12.1 MB

class Solution {
public:
    int wateringPlants(vector<int>& plants, int cap) {
        int ans = 0;
        int curr = cap;

        for(int i = 0; i < plants.size(); i++){
            if(curr < plants[i]){
                ans += (2 * i);   
                curr = cap;      
            }
            ans++;               
            curr -= plants[i];  
        }
        return ans;
    }
};