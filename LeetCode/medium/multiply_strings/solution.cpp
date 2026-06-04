// Problem: Multiply Strings
// Difficulty: medium
// Runtime: 3 ms
// Memory: 9.7 MB

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; 

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n + m, 0); 
        string anss = "";

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                ans[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }   

        int carry = 0;
        for(int i = n + m - 1; i >= 0; i--){
            int val = ans[i] + carry;
            ans[i] = val % 10;
            carry = val / 10;
        }

        for(int i = 0; i < ans.size(); i++){
            if (anss.empty() && ans[i] == 0) continue; 
            anss += (ans[i] + '0'); 
        }
        
        return anss.empty() ? "0" : anss;
    }
};