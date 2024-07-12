class Solution {
public:
    //INTUTION :- SO FIRST WE WILL REVERSE WHOLE STRING AND AFTER REVRESING WE CAN THE WORDS AT THE PLACE AT WHICH WE WANTED. NOW WE WILL HAVE TO JUST REVERSE THE WORDS ON EACH PLACE. AND ONE EXTRA THING WHICH WE HAVE TO KEEP REMEMBER IS WHEN WE ARE REVERSING THE STRING WE HAVE ASKED THAT WE HAVE TO KEEP MAINTAIN THE ONLY ONE SPACES AFTER ONE WORD.
    void reverseWord(string &s,int left,int right){
        while(left<right){
            char c=s[left];
            s[left]=s[right];
            s[right]=c;

            right--;
            left++;
        }
    }

    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int left=0;
        int right=0;
        int i =0;
        while(i<s.length()){
            //AS FAR AS WE ARE GETTING THE CHARCTER JUST PUT THEM INTO THE PLACE WITHOUT ANY GAPE.
            while(i<s.length() && s[i]!=' '){
                s[right++]=s[i++];
            }

            if(left<right){
                //AFTER THIS CONDITION WILL BECOME TRUE IF OUR I GET A BLANK CHARCTER MEANS WE ALREADY GET A WORD AND NOW JUST REVERSE THAT WORD.
                reverseWord(s,left,right-1);
                
                //AFTER REVERSING THE WORD GIVE ONE SPACE FOR IT AND THEN UPDATE THE LEFT POINTER TO NEW PLACE WITH RIGHT POINTER AND THEN THE SAME PROCESS FROM ABOVE BE REPEATED UNTILL WE TRAVERSE THORUGH THE LAST CHARACTER.
                s[right]=' ';
                right++;
                left=right;
            }
            i++;
        }
        //AS WE ARE ALWAYS ADDING THE SPACE AFTER EVERY WORD AT THE TIME OF LAST WORD THERE WILL BE ONE EXTRA SPACE AFTER THAT SO WE JUST NEED REMOVE THAT SPACE FROM THE STRING.
       return s.substr(0,right-1);
    }
};