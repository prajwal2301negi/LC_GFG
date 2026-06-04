// Problem: Sender With Largest Word Count
// Difficulty: medium
// Runtime: 24 ms
// Memory: 76 MB

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string , int> count;
        for(int i = 0, n = senders.size(); i < n; ++i){
            int words = 1;
            for(int j = 0, m = messages[i].length(); j < m; ++j){
                if(messages[i][j] == ' ') ++words;
            }
            count[senders[i]] += words;
        }
        string res;
        int maxCount = 0;
        for(auto& [sender , total] : count){
            if (total > maxCount || (total == maxCount && sender > res)) {
                maxCount = total;
                res = sender;
            }
        }
        return res;
    }
};