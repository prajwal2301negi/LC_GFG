// Problem: Reverse Words in a String
// Difficulty: medium
// Runtime: 0 ms
// Memory: 10.1 MB

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            
            int start = i;
            
            while (i < n && s[i] != ' ') {
                i++;
            }
            reverse(s.begin() + start, s.begin() + i);
        }

        reverse(s.begin(), s.end());
        
        int j = 0;
        while (j < n and s[j] == ' ') j++;

        int k = n-1;
        while(k>=j and s[k] == ' ')k--;

        if (j > k) return ""; 
        string trimmed = s.substr(j, k - j + 1);
        
        string result = "";
        for (int p = 0; p < trimmed.size(); p++) {
            if (trimmed[p] == ' ') {
                if (p > 0 && trimmed[p-1] != ' ') {
                    result += ' ';
                }
            } else {
                result += trimmed[p];
            }
        }

        return result;
    }
};
