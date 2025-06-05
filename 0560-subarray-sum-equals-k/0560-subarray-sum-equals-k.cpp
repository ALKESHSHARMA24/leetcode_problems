class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int totalSum=0;
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            if(sum==k){
                // cout<<"index "<<i<<endl;
                totalSum++;
            }

            if(mp.find(sum-k)!=mp.end()){
                // cout<<"index "<<i<<endl;
                totalSum=totalSum+mp[sum-k];
            }
            mp[sum]++;
          
        }
        return totalSum;  
    }
};