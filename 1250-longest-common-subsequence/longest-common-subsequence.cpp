class Solution {
public:
    int solve(int i, int j, string &t1, string &t2, vector<vector<int>> &dp) {
        // base case
        if (i == 0 || j == 0)return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (t1[i-1] == t2[j-1]) {
            return dp[i][j] = 1 + solve(i -1, j - 1, t1, t2, dp);
        }
        //don't match
        else {
            int skip1 = solve(i - 1, j, t1, t2, dp);
            int skip2 = solve(i, j - 1, t1, t2, dp);
            return dp[i][j] = max(skip1, skip2);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(n, m, text1, text2, dp);
    }
};
