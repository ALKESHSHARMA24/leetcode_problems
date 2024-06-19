class Solution {
public:
    
    const int MOD = 1e9 + 7;
    long long power(long long n,long long m){
        long long localAns=0;
        if(m==0){
            return 1;
        }
        if(m%2==0){
            
            // SO HERE WE CAN'T DIRECTLY USE THE (N*N,M/2) BECAUSE IT WILL LEAD THE OVERFLOW SITUATION AS N*N WILL CREATE THE LONG LONG OVERFLOW IN SOME CASES. SO IN PLACE OF THAT WE WILL USE JUST (N,M/2) SO THAT IT WILL JUST RESTRICT THE VALUE WITHIN THE LONG LONG RANGE BECAUSE IT WILL ONLY HOLD ONE VARAIBLE VALUE AT A TIME. 
           //AND THEN WE CAN DO A SQUARE OF IT AND AFTER TAKING THE MODULO OF SQUARE EVERY TIME WE ENSURING THAT IT WILL BE ALWAYS WITHIN THE RANGE OF LONG LONG.

            localAns=power(n,m/2);
            localAns=(localAns*localAns) % MOD;
            return localAns;
        }else{ 
            localAns=power(n,(m-1)/2);
            localAns=(n*(localAns*localAns)) % MOD;
            return localAns ;
        }

    }
    int countGoodNumbers(long long n) {
        /* we can't directly find the solution using the multipicaion number of possible number      according to the odd and even places like 
        for even places we have choice from(0,2,4,6,8)
        for odd places we have choices from (2,3,5,7) 
        so we use direct calucation like 5*4*5*4*.... it will overflow the int value and also the given will be 2^15 which already get overflow from int ranage      

        now what can we do is just finding the number of odd even place then we just have to do simple calcuation like (5^even_places) * (4^odd places)*/

        //find the total number of places n
        long odd=n/2;
        long even=(n/2)+n%2;

        //to find the power of 5 and 4
        int ans=(power(4,odd)*power(5,even)) % MOD;
        return ans;
    }
};