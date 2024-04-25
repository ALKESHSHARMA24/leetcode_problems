class Solution {
public:
    int majorityElement(vector<int>& nums) {
         map<int,int> freq; 
        for (int num : nums)
            freq[num]++;
        pair<int,int> mx = {INT_MIN, INT_MIN}; 
        for (auto item : freq)
        {
            if (mx.second < item.second){
                mx = {item.first, item.second}; 
            }
        }
        return mx.first;
    }
};