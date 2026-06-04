// Problem: Sorting the Sentence
// Difficulty: easy
// Runtime: 3 ms
// Memory: 8.3 MB

class Solution {
public:
    string sortSentence(string s) 
    {
        map<int,string> mpp;
        string temp;
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                mpp[s[i]-'0'] = temp;  
                temp = "";
                i++;  
            }
            else
            {
                temp += s[i];
            }
        }
        
        string ans;
        for(auto &it : mpp)
        {
            ans += it.second + " ";
        }
        ans.pop_back();  
        return ans;
    }
};