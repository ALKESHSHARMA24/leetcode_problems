class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int left=0;
        int right=0;
        int maxSum=INT_MIN;
        int sum=0;
        while(right<=nums.size()-1){
            sum+=nums[right];
            maxSum=max(sum,maxSum);
            if(sum<0){
                sum=0;
                right++;
                left=right;
            }else{
                right++;
            }
        } 
        cout<<"left-->"<<left<<" "<<right<<endl;
        return maxSum;  
    }
};