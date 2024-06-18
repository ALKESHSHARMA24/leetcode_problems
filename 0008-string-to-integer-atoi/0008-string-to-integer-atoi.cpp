class Solution {
public:
    int myAtoi(string s) {
        int length = s.length();
        int len = 0;
        int result = 0;
        int sign = 1;

        // first check the white spacee
        while (len < length && s[len] == ' ') {
            len++;
        }

        // now check for the sign only once after getting first sign after that
        // there should not be any other sign be available in the string for a
        // valid string.
        if (len < length && (s[len] == '+' || s[len] == '-')) {
            sign = (s[len] == '-') ? -1 : 1;
            len++;
        }

        while (len < length && (s[len] >= '0' && s[len] <= '9')) {
            int num = s[len] - '0';

            // check overflow and underflow condition
            /*
            if suppose that our result is only one digit away to reach out the
INT_MAX value and then if the next value should not greater than INT_MAX. For
this first we need to subsract the last digit and divide the number by 10
because first we are multiplying the number with 10 then adding into the result.
That's why we just can't be sure with just substracting the last num from the
result to ensure the overflow. */

            if (result > (INT_MAX - num) / 10) {
                return (sign == 1) ? INT_MAX
                                   : INT_MIN; // return result based on sign
            }

            result = result * 10 + num;
            len++;
        }
        return result * sign;
    }
};