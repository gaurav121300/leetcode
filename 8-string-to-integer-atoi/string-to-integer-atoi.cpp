class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Build the number
        long long ans = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // 4. Check overflow BEFORE calculating ans
            int limit = (sign == 1) ? 7 : 8;

            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > limit)) {

                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            ans = ans * 10 + digit;

            i++;
        }

        // 5. Apply sign
        return ans * sign;
    }
};