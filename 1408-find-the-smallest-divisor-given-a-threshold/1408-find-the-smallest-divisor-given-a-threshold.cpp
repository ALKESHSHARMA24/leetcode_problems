class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=0;
        int end=nums.size()-1;
        int minDivisor=0;
        int maxDivisor=1;
        int largestValue=0;

        for (int num : nums) {
            largestValue = std::max(largestValue, num);
        }

        minDivisor = largestValue;

        while(maxDivisor<=largestValue){

            int mid=maxDivisor+(largestValue-maxDivisor)/2;
            int divisorSum=0;
            start=0;
            while(start<=end){
                divisorSum+=ceil(nums[start]/(double)mid);
                start++;
            }

            if(divisorSum<=threshold){
                if(mid<=minDivisor){
                    minDivisor=mid;
                }
                largestValue=mid-1; 
            }else{
                maxDivisor=mid+1;
            }

        }
        return minDivisor;
    }
};