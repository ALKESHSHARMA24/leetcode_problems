class Solution {
public:

    
    int romanToInt(string s) {
        //FIRST MAP THE ALL CHARACTER WHICH ARE GIVEN AS A INFROMATION.
       unordered_map<char,int> mp;
       mp['I']=1;
       mp['V']=5;
       mp['X']=10;
       mp['L']=50;
       mp['C']=100;
       mp['D']=500;
       mp['M']=1000;
       
       int result=mp[s[s.length()-1]];
       
       for(int i=s.length()-2;i>=0;i--){
        //IF THE CURRENT CHARCTER VALUE IS LESS THAN THE UPCOMING CHARCTER THAN SIMPLY DECREMENT THE CURRENT CHRACTER'S VALUE FROM THE RESULT.
         char c=s[i];
         if(mp[c]<mp[s[i+1]]){

            result=result-mp[c];

         }else{
            //ADD THE VALUE OF CURRENT CHRACTER VALUE INTO THE RESULT
            result=result+mp[c];
         }
       }
       return result;
    }
};