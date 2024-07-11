class Solution {
public:
//UNDERSTAND THE QUESTION CORRECT IT IS ASKING SUM OF THE BEAUTY OF ALL ITS SUBSTRING'S MOST FREQ-LESS FREQ.NOT THE TOTAL NUMBER OF BEAUTY STRING POSSIBLES.
    int beautySum(string s) {
        int result=0;
        unordered_map<char,int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp.clear();
            for (int j = i; j < s.length(); j++) {
                mp[s[j]]++;
                
                int maxFreq = 0;
                int lessFreq = INT_MAX;
                //after updating the map we need to find the max and min for that substring.
                for (const auto& p : mp) {
                    if (p.second > maxFreq) {
                        maxFreq = p.second;
                    }
                    if (p.second < lessFreq) {
                        lessFreq = p.second;
                    }
                }
                //and now add the difference of max and min into result for every substring.
                if (mp.size() > 1) {
                    result += maxFreq - lessFreq;
                }
            }
        }
        return result;
    }
};