// Problem: Minimum Add to Make Parentheses Valid
// Difficulty: medium
// Runtime: 0 ms
// Memory: 8.6 MB

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        if(n == 1) return 1;

        stack<char>st;

        for(int i =0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(!st.empty() and st.top() == '(') st.pop();
                else st.push(s[i]);
            }
        }
        return st.size();
        
    }
};