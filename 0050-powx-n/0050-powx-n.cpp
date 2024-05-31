class Solution {
public:

    double solve(double x,long n){
        
        if(n==0){
            return 1;
        }
        // we can write the negatibe power to any base like (1/base)^positive(power). so here we try to convert the negative power to positive power so that our calculation loook easy.
        if(n<0){
            return solve(1/x,-n);
        }

        if(n%2==0){
            return solve(x*x,n/2);
        }else{
            
            //this function over get exectue as our n/2 will become 1 in the second call stack recursion which will give the final answer to us.
            return x * solve(x*x,(n-1)/2);
        }
    }
    double myPow(double x, int n) {
        
        //long
        return solve(x,(long)n);
        
    }

};