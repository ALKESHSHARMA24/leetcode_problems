class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=0;
        int end=nums.size()-1;
        int minDivisor=0; //always true answer as are dividing with the largest 
        int maxDivisor=1; //may be possible if only one element case

        int largestValue=0; //finding that largest element from the array

        for (int num : nums) {
            largestValue = std::max(largestValue, num);
        }

        minDivisor = largestValue;

        while(maxDivisor<=largestValue){    //performs binary search on the possible answers 

            int mid=maxDivisor+(largestValue-maxDivisor)/2;
            int divisorSum=0;
            start=0;
            while(start<=end){
                divisorSum+=ceil(nums[start]/(double)mid); //imp to type cast into double to use ceil functionality
                start++;
            }

            if(divisorSum<=threshold){

                if(mid<=minDivisor){ //compare with old divisor to check if we get new smallest divisor
                    minDivisor=mid;
                }

                largestValue=mid-1; //there can be more smallest divisor possible
            }else{
                maxDivisor=mid+1;  //else divisor lies in the right part.
            }

        }
        return minDivisor;
    }
};