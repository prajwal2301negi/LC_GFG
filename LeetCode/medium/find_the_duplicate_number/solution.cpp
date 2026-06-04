// Problem: Find the Duplicate Number
// Difficulty: medium
// Runtime: 32 ms
// Memory: 65.1 MB

class Solution {
public:
    int findDuplicate(vector<int>& arr) {

        int n = arr.size();
        int xorr, x;
        
        sort(arr.begin(), arr.end());

        for(int i=0; i<n-1; i++){
            xorr = arr[i] ^ arr[i+1];

            if(xorr == 0){
                x = i;
                break;
            }
        }
        return arr[x];
    }
};