// Problem: Shuffle String
// Difficulty: easy
// Runtime: 4 ms
// Memory: 20.5 MB

class Solution {
public:
   static bool comp(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    }
    string restoreString(string s, vector<int>& indices) {
        vector<pair<char, int>> vec;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vec.push_back({s[i], indices[i]});
        }
        sort(vec.begin(), vec.end(), comp);
        for (int i = 0; i < n; i++) {
            s[i] = vec[i].first;
        }
        return s;
    }
};