// Problem: Destination City
// Difficulty: easy
// Runtime: 3 ms
// Memory: 15.8 MB

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> freq;

        for (auto string : paths) {
            freq[string[0]] += 2;
            freq[string[1]] += 1;
        }

        for (auto val : freq) {
            if (val.second == 1) {
                return val.first;
            }
        }

        return " ";
    }
};