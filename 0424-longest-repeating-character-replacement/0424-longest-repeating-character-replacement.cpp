class Solution {
public:
    int characterReplacement(string s, int k) {
        //bruteforce:- find the all sub arrays then check the how many different character is occuring in that subarrays length and if it's exist more than the k then break;
        int maxFreq=0;
        for(int i=0;i<s.size();i++){
            vector<int> arr(26,0);
            int Curr_maxfreq=0;
            for(int j=i;j<s.size();j++){
                arr[s[j]-'A']++;
                 Curr_maxfreq=max(Curr_maxfreq,arr[s[j]-'A']);
                 //The formula to find the odd character  in the continguos subarray with same charcter
                if(((j-i+1)-Curr_maxfreq)>k){
                    break;
                }
                maxFreq=max(j-i+1,maxFreq);
            }
 
        }
        return maxFreq;;
    }
};