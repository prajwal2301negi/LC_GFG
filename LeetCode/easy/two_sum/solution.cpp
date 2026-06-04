// Problem: Two Sum
// Difficulty: easy
// Runtime: 147 ms
// Memory: 14 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){

        
             if(nums[i]+nums[j]==target){
                ans.push_back(i);
                
            
                ans.push_back(j);

            

                }
        }

    }
    cout<<"[";
    return ans;
    ans.pop_back();
    cout<<",";
    return ans;

    cout<<"]";
    }
        
    
};