class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(nums,0,ans,curr);
        return ans;
    }

    void solve(vector<int>& nums,int idx,vector<vector<int>> &ans,vector<int>curr){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }

        solve(nums,idx+1,ans,curr);

        curr.push_back(nums[idx]);
        solve(nums,idx+1,ans,curr);

    }
};