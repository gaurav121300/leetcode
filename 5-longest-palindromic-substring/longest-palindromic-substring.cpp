class Solution {
public:

    int expand(string &s, int left, int right) {

        while(left >= 0 &&
              right < s.size() &&
              s[left] == s[right]) {

            left--;
            right++;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < s.size(); i++) {

            // Odd length
            int odd = expand(s, i, i);

            // Even length
            int even = expand(s, i, i + 1);

            int len = max(odd, even);

            if(len > maxLen) {
                maxLen = len;

                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};