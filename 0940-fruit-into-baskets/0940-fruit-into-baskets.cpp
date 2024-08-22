class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       /*best approach:- use sliding window technique update the  
      maxlength while every iteration untill it satisfy the given condiiton.use map strcuture in place of the
      set as we need to delete the elemetns til our windows satisfied the given condition
      and if we use the set then we can't delete the all number of elements which are breaching the window condition.*/

        int left=0;
        int right=0;
        int maxlen=0;
        unordered_map<int,int>mp;
        while(right<fruits.size()){
          mp[fruits[right]]+=1;
          if(mp.size()>2){
            //if breaching the given condition then start updating the left pointer until we removed the 
            //element which was violating the condition 
            mp[fruits[left]]-=1;
            //imp to delete the keys from the map if its presense value become 0 so that it doesn't count in the map.size() method.
            if(mp[fruits[left]]==0)mp.erase(fruits[left]);
            left++;
          }
          //not allowing you to go more than my recent highest length untll and unless you satify the given condition
          if(mp.size()<3){
             maxlen=max(maxlen,right-left+1); 
          }
          right++;
        }
        return maxlen;
    }
};