// Problem: Repeated String Match
// Difficulty: medium
// Runtime: 7 ms
// Memory: 9.7 MB

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        string temp = a;
        int count = 1;

        while (temp.size() < m) {
            temp += a;
            count++;
        }
        // Case1
        if (temp.find(b) != string::npos) return count;

        // Case2 starts at the end of one 'a' and wraps into the next.
        temp += a;
        if (temp.find(b) != string::npos) return count + 1;

        return -1;
    }
};