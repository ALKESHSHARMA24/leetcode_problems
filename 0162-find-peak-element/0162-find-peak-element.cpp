class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=1;
        int end=nums.size()-1;
        int peakElement=0;
        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[end]>nums[end-1]){
            return end;
        }
        else{
            end=nums.size()-2;
            while(start<=end){
                int mid=start+(end-start)/2;
                //WE ARE ASSUMING THERE IS ONLY ONE PEAK IN THE ARRAY
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    // peakElement
                    return mid;
                }else if(nums[mid]>nums[mid-1]){
                    start=mid+1;
                }else if(nums[mid]>nums[mid+1]){
                    end=mid-1;
                }else{
                    /*
                    NOW SUPPOSE IF THERE ARE MULTIPLE PEAKS IN OUR ARRAY SO WE CAN EITEHR DECREASE THE END BY 1 OR INCREASE THE 
                    START BY 1 AND IT IS SURE THAT THERE WILL BE PEAK ON BOTH SIDE FROM THAT ELEMENT AS 
                    THIS CONDITION WILL ONLY BE TRUE WHEN OUR ELEMENT IS REVERSE PEAK FROM THE GRAPH VISUALIZATION PERSPECTIVE SO THAT'S WHY WE
                    ARE SURE THAT OUR THERE WILL BE PEAK ELEMENT IN BOTH SIDE FROM THAT ELEMENT .*/

                    start=mid+1;  // OR END = MID-1;
                }
                
            }
        }
        return -1;
    }
};