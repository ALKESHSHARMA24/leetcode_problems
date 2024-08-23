class Solution {
public:
    int characterReplacement(string s, int k) {
        //better Apporach:- use two pointer and sliding window
         int left=0;
         int right=0;
         int maxLen=0;
         int maxFreq=0;
          unordered_map<char,int>mp;
         while(right<s.size()){
            mp[s[right]]++;
            maxFreq=max(maxFreq,mp[s[right]]);//1 1 2 2
            //using the formula "(right-left+1)-maxFreq" i can calculate that how many different character are occuring in the the present window and if it exceeeds more than the k than i have reinitialise the window untill it comes underthan k and only then i will go forward. to increase my window using right pointer. 
            while((right-left+1)-maxFreq>k){//0 1 1 2
                mp[s[left]]--;
                for(const auto ele:mp){
                     maxFreq=max(maxFreq,ele.second);
                }
                left++;
            }
  
            //Now my winddow is satisfying all the given constraints so now i can calculate the maxlength for the current window and update it where it needs.
                maxLen=max(maxLen,right-left+1);//1 2 3 4
            // }
            right++;
         }
         return maxLen;
    }
};