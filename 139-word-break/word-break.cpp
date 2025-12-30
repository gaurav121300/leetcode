class Solution {
public:
    bool solve(int idx, string &s,
               unordered_set<string> &st,
               vector<int> &dp) {

        if (idx == s.length()) return true;

        if (dp[idx] != -1) return dp[idx];

        string temp = "";
        for (int i = idx; i < s.length(); i++) {
            temp += s[i];

            if (st.count(temp)) {
                if (solve(i + 1, s, st, dp)) {
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return solve(0, s, st, dp);
    }
};
