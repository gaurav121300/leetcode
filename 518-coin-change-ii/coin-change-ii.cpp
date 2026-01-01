class Solution {
public:
    int solve(int idx,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(idx == 0 && amount % coins[0] == 0) return 1;
        if(idx == 0 && amount % coins[0] != 0) return 0;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int notPick = solve(idx-1,amount,coins,dp);
        int pick = 0;
        if(amount >= coins[idx]) pick = solve(idx,amount - coins[idx],coins,dp);
        return dp[idx][amount] = notPick + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};