// Problem: Sum of Subarray Minimums
// Difficulty: medium
// Runtime: 4 ms
// Memory: 47.2 MB

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNextSmaller(arr);
        vector<int> prev = findPrevSmaller(arr);

        int total = 0;
        int MOD = 1e9+7;

        int n = arr.size();

        for(int i =0;i<n;i++){
            long long left = i-prev[i];
            long long right = nse[i] - i;
            total = (total + (right * left % MOD * arr[i] % MOD) % MOD) % MOD;
        }
        return total;

    }

    vector<int> findPrevSmaller(vector<int>& arr){
        
        stack<int> st;
        int n = arr.size();
        vector<int> prev(n);

        for(int i =0;i<n;i++){
            while(!st.empty() and arr[st.top()]>=arr[i]){
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    vector<int> findNextSmaller(vector<int>&arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n);
        for(int i = n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]>arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
};