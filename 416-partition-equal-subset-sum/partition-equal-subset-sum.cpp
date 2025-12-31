class Solution {
public:
    bool solve(int i,vector<int>& nums,int total,vector<vector<int>> &dp){
        if(total == 0) return true;
        if(i == 0) return (nums[i] == total);

        if(dp[i][total] != -1) return dp[i][total];

        bool notPick = solve(i-1,nums,total,dp);
        bool pick = false;
        if(nums[i] <= total){
            pick = solve(i-1,nums,total-nums[i],dp);
        }
        return dp[i][total] = pick || notPick;
    }
    bool subset(int total,vector<int> &nums){
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
      return  solve(n-1,nums,total,dp);

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n;i++){
            total += nums[i];
        }

        if(total % 2 != 0) return false;

        return subset(total/2,nums);
    }
};