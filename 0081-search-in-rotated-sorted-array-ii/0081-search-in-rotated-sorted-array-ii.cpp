class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        //int pos=-1;

    /*
    IN ROTATED ARRAY SEARCH THE MOST KEY THING IS TO FIRST FIND THE SORTED PART AND IF ELEMENTS LIE IN THAT
     PART THEN DO SEARCH IN THAT PART AND ELEMENATE THE OTHER PART
    */
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return true;   
            }
            else if(nums[mid]==nums[start] && nums[mid]==nums[end]){
                start=start+1;
                end=end-1;
            }
            // IF ELEMENT LIES IN THE FIRST SORTED HALF
            else if(nums[mid]>=nums[start] ){
                if(nums[mid]>=target && target>=nums[start]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
             // IF ELEMENT LIES IN THE OTHER UNOSRTED HALF 
            }else if(nums[mid]<=nums[end]){
                if(nums[mid]<=target && target<= nums[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
                
            }
        }
        return false;
    }
};