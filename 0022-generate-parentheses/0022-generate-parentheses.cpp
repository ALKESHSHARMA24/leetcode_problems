class Solution {
public:

    void generateParenthessis(string current,int openCounter,int closeCounter,int n,vector<string>& result){

        if(openCounter==n && closeCounter==n){
            result.push_back(current);
            return;
        }
        if(openCounter < n){
            // openCounter++;
            // current+='(';
            generateParenthessis(current+'(',openCounter+1,closeCounter,n,result);

        }
        if(openCounter > closeCounter){
            // closeCounter++;
            // current+=')';
            generateParenthessis(current+')',openCounter,closeCounter+1,n,result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthessis("",0,0,n,result);
        return result;
    }
};
    