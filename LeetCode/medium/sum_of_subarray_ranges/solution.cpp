// Problem: Sum of Subarray Ranges
// Difficulty: medium
// Runtime: 8 ms
// Memory: 16 MB

class Solution {
public:
    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmall(n, n); 
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            if (!st.empty()) nextSmall[i] = st.top();
            st.push(i);
        }
        return nextSmall;
    }

    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmall(n, -1); 
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            if (!st.empty()) prevSmall[i] = st.top();
            st.push(i);
        }
        return prevSmall;
    }

    vector<int> nextLarger(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            if (!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevLarger(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            if (!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long minOfSubArray(vector<int>& nums){
        vector<int> prevS = prevSmaller(nums);
        vector<int> nextS = nextSmaller(nums);
        long long total = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int left = i-prevS[i];
            int right = nextS[i]-i;
            total += (left * right * (long long)nums[i]);
        }
        return total;
    }

    long long maxOfSubArray(vector<int>& nums){
        vector<int> prevL = prevLarger(nums);
        vector<int> nextL = nextLarger(nums);

        int n = nums.size();

        long long total = 0;

        for(int i = 0;i<n;i++){
            int left = i-prevL[i];
            int right = nextL[i]-i;

            total += (left * right * (long long)nums[i]);
        }
        return total;
    }

  

    long long subArrayRanges(vector<int>& nums) {
        return maxOfSubArray(nums) - minOfSubArray(nums);
    }
};