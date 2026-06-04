// Problem: Sum of Beauty of All Substrings
// Difficulty: medium
// Runtime: 115 ms
// Memory: 8.9 MB

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {0}; 

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxi = 0;
                int mini = 1e9;

                for (int m = 0; m < 26; m++) {
                    if (freq[m] > 0) {
                        maxi = max(maxi, freq[m]);
                        mini = min(mini, freq[m]);
                    }
                }
                sum += (maxi - mini);
            }
        }
        return sum;
    }
};