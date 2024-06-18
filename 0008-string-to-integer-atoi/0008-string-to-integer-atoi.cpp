class Solution {
public:
    int myAtoi(string s) {
         int length = s.length();
        int i = 0;
        int result = 0;
        int sign = 1;

        // Skip leading whitespaces
        while (i < length && s[i] == ' ') {
            i++;
        }

        // Check for sign
        if (i < length && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert characters to integer
        while (i < length && s[i] >= '0' && s[i] <= '9') {
            int num = s[i] - '0';

            // Check for overflow and underflow before updating result
            if (result > (INT_MAX - num) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + num;
            i++;
        }

        return result * sign;
    }
};