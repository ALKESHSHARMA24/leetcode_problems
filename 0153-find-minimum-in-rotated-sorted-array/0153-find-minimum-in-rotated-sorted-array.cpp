class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int smallest=INT_MAX;

        if(nums[start]<=nums[end]){
            return nums[start];
        }
        else {
            while(start<=end){
                int mid=start+(end-start)/2;

                if(nums[mid]>=nums[start]){
                    if(nums[start]<=smallest){
                        smallest=nums[start];
                    }
                    start=start+1;
                }else
                {
                    if(nums[mid]<=smallest){
                        smallest=nums[mid];
                        
                    }
                    end=end-1;
                }
             }
            return smallest;
        }
       
    }
};