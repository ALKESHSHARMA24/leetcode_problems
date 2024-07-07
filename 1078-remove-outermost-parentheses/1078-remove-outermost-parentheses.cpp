class Solution {
public:
    string removeOuterParentheses(string s) {
        /*
        INTITUTION :-  SO IN THIS TYPE OF QUESTION WE HAVE TO CHECK THAT IS THERE ANY OUTER MOST PARENTHESIS AVAILABLE OR NOT. AND IF THERE IS ALREADY ONE OUTER PARENTHESIS IS BE AVAILABLE IN THE STACK. THEN SIMPLY ADD THE ALL UPCOMING PARENTHESIS. 
        AND WE CAN MAKE IT SURE USING THE STACK.SIZE() METHOD TO FIND WETHER OUR STACK HAS THAT ONE PARENTHIS AVAILABL OR NOT.
        */
        string finalParenthesis="";
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='('){
                // IF SIZE IS GREATER THAN 0 MEANS ALREADY ONE OUTER PARENTHESIS IS IN THE STACK AND IF NOT MEANS NOW IT WILL BECOME THAT OUTERMOST PARENTHESIS. ALSO IF IT IS INNER THAN ADD IT TO STRING.
                if(st.size()>0){
                    finalParenthesis+=s[i];
                }
                st.push(c);
            }else{
                /*
                NOW TO CHECK THAT DO WE HAVE TO ADD THE PARENTHSIS PAIR OR NOT FIRST NEED TO CHECK THAT WETHER THIS CLOSE PARENTHESIS IS FOR OUTER PARENTHSIS OR INNER. IF IT IS FOR INNER THAN SIMPLY ADD IT TO RESULT STRING.AND WE CAN FIND IT ONLY IF WE DO POP THAT CHARCTER OUTER PARENTHESIS PAIR THEN
IS OUR STACK IS BECOME EMPTY OR NOT IF IT IS NOT EMPTY THEN IT WILL BE OUR INNER PAIR AND THEN SIMPLY ADD IT TO THE RESULT STRING.
*/
                st.pop();
                if(st.size()>0){
                    finalParenthesis+=c;
                }

            }
        }
        return finalParenthesis;
    }
};