class Solution {
public:
    int characterReplacement(string s, int k) {
        //opimal Apporach:- use two pointer and sliding window
         int left=0;
         int right=0;
         int maxlen=0;
         int maxFreq=0;
         int length=0;
          unordered_map<char,int>mp;
           
         while(right<s.size()){
            mp[s[right]]++;
            maxFreq=max(maxFreq,mp[s[right]]);
            
            //don't need to shrink the window  to find the biggerr length.just maintain the window size untill we get the new winodw who satisffy the given condition
            if((right-left+1)-maxFreq>k){
                mp[s[left]]--;
                left++;
            }
           //if find that window which  matches all the requirenments then udpate the maxlengh.
            if((right-left+1)-maxFreq<=k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
         }
         
         return maxlen;
    }
};