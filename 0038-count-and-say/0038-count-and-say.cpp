class Solution {
public:
    // Function for Run-Length Encoding (RLE)
    string RLE(string s) {
        int count = 1;     // Initialize count of consecutive characters
        string ans = "";   // Initialize result string
        int i = 0;         // Initialize index for iterating through string
        
        // Iterate through the string 's'
        while (i < s.length()) {
            // Check if current character is the same as the next one
            if (i + 1 < s.length() && s[i] == s[i + 1]) {
                count++;   // Increment count if consecutive characters are same
            } else {
                // Append count (converted to character) followed by the character to 'ans'
                ans += (count + '0');
                ans.push_back(s[i]);
                count = 1; // Reset count for next character sequence
            }
            i++; // Move to the next character in 's'
        }
        
        return ans; // Return the run-length encoded string
    }
    
    // Function to generate the n-th term of the "Count and Say" sequence
    string countAndSay(int n) {
        if (n == 1)
            return "1"; // Base case: n = 1, return "1"
        
        // Recursively compute (n-1)-th term of the sequence
        string s = countAndSay(n - 1);
        
        // Apply Run-Length Encoding to the (n-1)-th term
        return RLE(s); // Return the run-length encoded result
    }
};