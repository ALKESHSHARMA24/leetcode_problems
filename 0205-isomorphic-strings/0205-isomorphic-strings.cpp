class Solution {
public:
    bool isIsomorphic(string s, string t) {

       //TO FIND THE MAPPING OF EACH CHRACTER IN BOTH STRING
       unordered_map <char,char> charST;
       unordered_map <char,char> charTS;

       for(int i=0;i<s.length();i++){
            char charS=s[i];
            char charT=t[i];

            //first check wether the charcter is already mapped or not
            if(charST.find(charS) != charST.end()){//this means key is already present in the map
               if(charST[charS]!=charT){ //IF CHARCTER IS PRESENT BUT NOT MAPPED WITH CHRACTER OF T STRING MEANS IT CAN'T BE THE ISOMORPHIC
                 return false;
               }
            }else{
                //IF NOT MAPPED YET THAN MAPPED IT
                charST[charS]=charT;
            }

            //first check wether the charcter is already mapped or not
            if(charTS.find(charT) != charTS.end()){//this means key is already present in the map
               if(charTS[charT]!=charS){ //IF CHARCTER IS PRESENT BUT NOT MAPPED WITH CHRACTER OF T STRING MEANS IT CAN'T BE THE ISOMORPHIC
                 return false;
               }
            }else{
                //IF NOT MAPPED YET THAN MAPPED IT
                charTS[charT]=charS;
            }
       }
       return true;

    }
};