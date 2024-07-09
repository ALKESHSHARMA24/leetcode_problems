class Solution {
public:
    int maxDepth(string s) {
        //Stack approach 
        int MaxDepth=0;
        //int tempDepth=0;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else if(s[i]==')'){
                //every time when we get a close bracket then we will check that what was the previous maximum numbers of open bracket and if it is greater than our previous MaxDepth then simpy update it.

                if(st.size()>MaxDepth){
                    MaxDepth=st.size();
                }
                st.pop();
            }
        }
        return MaxDepth;
    }
}; 