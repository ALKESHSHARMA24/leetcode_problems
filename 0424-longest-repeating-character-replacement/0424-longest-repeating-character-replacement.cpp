class Solution {
public:
    int characterReplacement(string s, int k) {
        //better Apporach:- use two pointer and sliding window
         int left=0;
         int right=0;
         int maxlen=0;
         int maxFreq=0;
         int length=0;
          unordered_map<char,int>mp;
           
         while(right<s.size()){
            mp[s[right]]++;
            maxFreq=max(maxFreq,mp[s[right]]);
            

            if((right-left+1)-maxFreq>k){
                mp[s[left]]--;
                left++;
            }
           
            if((right-left+1)-maxFreq<=k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
         }
         
         return maxlen;
    }
};