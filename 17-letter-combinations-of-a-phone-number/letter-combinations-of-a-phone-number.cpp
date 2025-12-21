class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void dfs(int idx, string &digits, string &cur) {
        if (idx == digits.size()) {
            ans.push_back(cur);
            return;
        }
        int d = digits[idx] - '0';
        for (char c : mp[d]) {
            cur.push_back(c);
            dfs(idx + 1, digits, cur);
            cur.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string cur = "";
        dfs(0, digits, cur);
        return ans;
    }
};

// for (int i = 0; i < mp[d].size(); i++) {
//     char c = mp[d][i];   // single character
//     cur.push_back(c);
//     dfs(idx + 1, digits, cur);
//     cur.pop_back();      // backtrack
// }

