class Solution {
public:

     vector<vector<string>> combinations;

    bool isPalindrome ( string &s , int start , int end ){

        while(end >= start){
            if(s[end] != s[start]){
                return false;
            }
            end--;
            start++;
        }

        return true;
    }

    void helper(vector<string> &currentCombi ,  vector<vector<string>> &combinations , int index , string &s){

        if( index >= s.size()){
            combinations.push_back(currentCombi);
            return;
        }

        for(int i = index ; i < s.size(); i++){
            
            // for(int j = i ; j < s.size() ; j++){

                if( isPalindrome( s, index , i ) ){

                    currentCombi.push_back(s.substr( index , i-index+1 ));
                    helper( currentCombi , combinations , i + 1 , s );
                    currentCombi.pop_back();

                }
            // }
            
            
        }

    }

    vector<vector<string>> partition(string s) {
        
        vector<string> currentCombi;
        helper ( currentCombi , combinations , 0 , s);
        return combinations;

    }
};