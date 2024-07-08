class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix="";
        sort(strs.begin(),strs.end());

        for(int i =0;i<strs[0].length();i++){
            if(strs[0][i]!=strs[strs.size()-1][i]){
                return commonPrefix;
            }
            else{
                commonPrefix+=strs[0][i];
            }
        }

        return commonPrefix;
    }
};