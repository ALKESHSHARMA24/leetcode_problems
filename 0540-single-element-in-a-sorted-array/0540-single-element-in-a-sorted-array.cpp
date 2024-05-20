class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=1;
        int end=nums.size()-1;
        int singleElement=0;

        // TO ELIMINATE THE OVERHEAD OF EDGE CASES WE WILL JUST FIRSTLY CHECK ALL THAT EDGE CASES
        if(nums.size()==1){
            return nums[0];
        }
        else if (nums[0]!=nums[1]){
            return nums[0];
        }
        else if(nums[end]!=nums[end-1]){
            return nums[end];
        }
        else{
            end=nums.size()-1;
            while(start<=end){

                int mid=start+(end-start)/2;

                if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                    singleElement=nums[mid];
                    break;

                }
                else if((mid%2==0)){
                    if (nums[mid]==nums[mid+1]){
                        start=mid+1;
                    }else{
                        end=mid-1;
                    }
                }
                else 
                    if(nums[mid]==nums[mid+1]){
                        end=mid-1;
                    }else{
                        start=mid+1;
                    }
                

            }
            return singleElement;
        }
        
    }
};