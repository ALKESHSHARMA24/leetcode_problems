class Solution {
public:
    string largestOddNumber(string num) {
        
        int length=num.length();
        for (int i = length - 1; i >= 0; --i) {
            //TO FIND THE STRING IS ODD OR EVEN WE JUST HAVE TO CHECK THE LAST CHARCTER IS ODD OR EVEN IF IT IS NOT DIVISIBLE BY 2 THEN THE STRING WILL BE ODD.
            if ((num[i] - '0') % 2 != 0) {
                // NOW IF LAST CHARACTER IS ODD THEN IT WILL BE THE LARGEST ODD STRING AND THEN JUST RETURN THAT STRING.
                return num.substr(0, i + 1);
            }
        }
        
        // IF THERE IS NO ANY ODD SUBSTRING IS POSSIBLE THEN RETURN THE EMPTY STRING.
        return "";
    }
};