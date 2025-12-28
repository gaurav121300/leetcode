class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // Step 1: Palindrome table
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len == 1)
                    isPal[i][j] = true;
                else if (len == 2)
                    isPal[i][j] = (s[i] == s[j]);
                else
                    isPal[i][j] = (s[i] == s[j] && isPal[i+1][j-1]);
            }
        }

        // Step 2: dp for minimum cuts
        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (isPal[j+1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n-1];
    }
};
