class Solution {
public:

    int findNumbers(vector<int>& nums) {
        int totalEvens=0;
        for(int i=0;i<nums.size();i++){
            // if(nums[i]%2==0){
            //     totalEvens++;
            // }
            int temp=nums[i];
            int NumLength=0;
            while(temp>0){
                temp=temp/10;
                NumLength++;
            }
            
            if(NumLength%2==0)totalEvens++;
        }
        return totalEvens;
    }
};