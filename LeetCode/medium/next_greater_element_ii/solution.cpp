// Problem: Next Greater Element II
// Difficulty: medium
// Runtime: 3 ms
// Memory: 28.6 MB

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        vector<int> ans(n,-1);

        stack<int> st;
        st.push(nums[n-1]);

        for(int i =n-2;i>=0;i--){
            if(!st.empty() and st.top()>nums[i]){
                ans[i] = st.top();
                st.push(nums[i]);
            }
            else{
                while(!st.empty() and st.top()<=nums[i]) st.pop();
                if(!st.empty()) ans[i] = st.top();
                st.push(nums[i]);
            }
        }

        for(int i =n-1;i>=0;i--){
            if(!st.empty() and st.top()>nums[i]){
                ans[i] = st.top();
                st.push(nums[i]);
            }
            else{
                while(!st.empty() and st.top()<=nums[i]) st.pop();
                if(!st.empty()) ans[i] = st.top();
                st.push(nums[i]);
            }
        }

        return ans;
    }
};

// 1 2 1 1 2 1
// 2 -1 2 