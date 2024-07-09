class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> stringS;
        unordered_map<char,int> stringT;

        if(s.length()!= t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            stringS[s[i]]++;
            stringT[t[i]]++;
        }

        for( const auto pair:stringS){
            if(pair.second != stringT[pair.first]){
                return false;
            }
        }   
        
        return true;
    }
};