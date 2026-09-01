class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // Step 1: Remove leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }

        // Step 3: Build number
        int ans = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Step 4: Check overflow
            int limit = (sign == 1) ? 7 : 8;

            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;

            i++;
        }

        return ans * sign;
    }
};