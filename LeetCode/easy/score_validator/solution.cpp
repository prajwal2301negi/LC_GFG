// Problem: Score Validator
// Difficulty: easy
// Runtime: 7 ms
// Memory: 53.6 MB

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0;
        int counter = 0;

        for(const string& event: events){
            if(event == "W") counter++;
            else if(event == "WD" || event=="NB") score++;
            else score+= stoi(event);

            if(counter == 10) break;
        }
        return {score,counter};
    }
    
};