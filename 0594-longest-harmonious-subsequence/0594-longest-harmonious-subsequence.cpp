class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> CounterFreq;
        int MaxLength=0;

        for(int i=0;i<nums.size();i++){
            CounterFreq[nums[i]]++;
        }
        for(auto a : CounterFreq){
            if(CounterFreq.find(a.first-1) != CounterFreq.end()){
                MaxLength=max(MaxLength, a.second + CounterFreq[a.first-1]);
            }
        }
        return MaxLength;
    }
};