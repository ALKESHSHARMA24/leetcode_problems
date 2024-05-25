class Solution {
public:
    int strStr(string haystack, string needle) {

        int stringLength = haystack.length();
        int patternLength = needle.length();

        if (patternLength == 0) return 0; 
        if (stringLength < patternLength) return -1; 
        
        for (int i = 0; i <= stringLength - patternLength; i++) {
            bool patternMatch = true;
            for (int j = 0; j < patternLength; j++) {
                if (needle[j] != haystack[i + j]) {
                    patternMatch = false;
                    break;
                }
            }
            if (patternMatch) return i; 
        }
        
        return -1;
    }
};