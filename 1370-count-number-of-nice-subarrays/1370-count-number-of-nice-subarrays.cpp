class Solution {
public:
int helper(vector<int>& nums, int k) {
        
        /* If goal is negative, there 
        can't be any valid subarray sum*/
        if (k < 0) return 0;
        
        //Pointers to maintain the current window
        int l = 0, r = 0; 
        
        /* Variable to track the current 
        sum of elements in the window*/
        int sum = 0;      
        
        // Variable to count the number of subarrays
        int count = 0;   
        
        /* Iterate through the array 
        using the right pointer `r`*/
        while (r < nums.size()) {
            sum = sum + nums[r] % 2; 
            
            /* Shrink the window from the left
            side if the sum exceeds k*/
            while (sum > k) {
                sum = sum -  nums[l] % 2;  
                
                // Move the left pointer `l` forward
                l++;            
            }
            
            /* Count all subarrays ending at
            `r` that satisfy the sum condition*/
            count += (r - l + 1);
            
            // Move the right pointer `r` forward 
            r++; 
        }
        
        // Return the total count of subarrays
        return count;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};