class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int start=0;
      int end=nums.size()-1;
      while(start<=end){
        int mid=end-(start/2);
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            start=mid+1;
        }else if (nums[mid]>target){
            end=mid-1;
        }
      } 
      return start; 
      /*
      this will execute when the target element is not presenet in the array and at that our 
      start will be present at the position where the element has to be in the array if we have sorted array
      */
    }
};