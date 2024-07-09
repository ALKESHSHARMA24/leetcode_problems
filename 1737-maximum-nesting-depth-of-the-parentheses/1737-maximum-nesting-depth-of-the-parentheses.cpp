class Solution {
public:
    int maxDepth(string s) {
        //Without Stack approach 
        int maxDepth=0;
        int openCounter=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                openCounter++;
            }else if(s[i]==')'){
                if(openCounter>maxDepth){
                    maxDepth=openCounter;
                }
                openCounter--;
            }
        }
        
        return maxDepth;
    }
}; 