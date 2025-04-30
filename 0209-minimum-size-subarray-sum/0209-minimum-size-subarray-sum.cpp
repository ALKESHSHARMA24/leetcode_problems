class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left=0;
        int right=0;
        int currentSum=0;
        int minLength=INT_MAX;

        while(right<nums.size()){
            currentSum+=nums[right];

            if(currentSum>=target){
                // minLength=min(currentSum,right-left+1);

                while(currentSum>=target && left<=right){
                    minLength=min(minLength,right-left+1);
                    currentSum-=nums[left];
                    left++;
                }
            }    
            right++;        
        }   
        return minLength == INT_MAX ? 0 : minLength;

    }
};