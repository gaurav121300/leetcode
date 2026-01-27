class Solution {
public:
       int helper(int ind,int prev_ind,vector<int>&nums,vector<vector<int>> &dp){
           if(ind == nums.size()) return 0;

           if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind+1];
        int len = 0,take = 0;
        int notTake = 0 + helper(ind+1,prev_ind,nums,dp);
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
         take = 1 + helper(ind + 1,ind,nums,dp);
        }
        len = max(notTake,take);
        return dp[ind][prev_ind + 1] = len;
    // }
       }
    // int helper(int ind,int prev_ind,vector<int> &nums){
    //     if(ind == nums.size()) return 0;
    //     int len = 0,take = 0;
    //     int notTake = 0 + helper(ind+1,prev_ind,nums);
    //     if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
    //      take = 1 + helper(ind + 1,ind,nums);
    //     }
    //     len = max(notTake,take);
    //     return len;
    // }
    int lengthOfLIS(vector<int>& nums) {
        // int ans = helper(0,-1,nums);
        // return ans;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,-1,nums,dp);
    }
};