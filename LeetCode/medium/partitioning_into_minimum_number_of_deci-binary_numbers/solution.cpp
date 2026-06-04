// Problem: Partitioning Into Minimum Number Of Deci-Binary Numbers
// Difficulty: medium
// Runtime: 23 ms
// Memory: 16.6 MB

class Solution {
public:
    int minPartitions(string n) {
        int count = 0;

        while (true) {
            bool changed = false;

            for (char& ch : n) {
                if (ch != '0') {
                    ch--;
                    changed = true;
                }
            }

            if (!changed)
                break;

            count++;
        }

        return count;
    }
};