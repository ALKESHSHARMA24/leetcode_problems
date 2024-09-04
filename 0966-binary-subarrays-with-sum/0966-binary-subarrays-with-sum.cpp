class Solution {
private:

    int countArrays(vector<int>& nums,int goal){
        if(goal<0){
            return 0;
        }
        int totalSubArrays=0;
        int left=0;
        int right=0;

        int sum=0;
        while(right<nums.size()){
            sum+=nums[right];
            //shrink the window if sum exceeds the goal
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
          /* here we are using the concept that if after ading current element
           if our sum is less than the goal means it previous sub array's sum also be
           the less than that so we can directly count those number of sub aarays. */
            totalSubArrays+=(right-left+1);
            right++;
        }
        return totalSubArrays;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal<0){
            return 0;
        }
        //we know how to found the sub-arrays with the sum less than goal and here can take 
        //advantage of that.
        int totalSubArrays=countArrays(nums,goal)-countArrays(nums,goal-1);
        return totalSubArrays;
    }
};