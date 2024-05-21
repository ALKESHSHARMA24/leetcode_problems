//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	   
	    int start=0;
        int end=n-1;
        int smallest=INT_MAX;
        int index=0;
        if(arr[0]<=arr[n-1]){
	        return 0;
	    }
        /* APPROACH :-
        NOW SUPPOSE WE HAVE GIVEN THE SORTED ROTATED ARRAY AND NOW WE HAVE TO FIND THE MINIMUM ELEMENT FROM THT
        OUR SHOULD BE LIKE WE WILL CHECK FIRST THE SORTED PART AND IF THAT PART IS SORTED WE WILL SIMPLY
        TAKE THE ADVANTAGE OF SORTED ARRAY LIKE DIRECTLY ASSUMING THE FIRST ELEMENT WILL BE SMALLEST ALWAYS.
        NOW AFTER FINDING THE SMALLEST ELEMENT FROM THAT PART OF ARRAY,THEN WE WILL SIMPLY ELEMENATE THAT PART  
        WE WILL CHECK THE IF THERE IS MORE SMALLEST VALUE WHICH IS PRESENT IN THE OTHER UNSORTED PART AND
         IF YES THEN WILL UPDATE OUR MINIMUM VALUE.
        */
        else {
            while(start<=end){
                int mid=start+(end-start)/2;

                //CHECK SMALLEST FROM FIRST LEFT SORTED PART OF ARRAY
                if(arr[mid]>=arr[start]){
                    if(arr[start]<=smallest){
                        smallest=arr[start];
                        index=start;
                    }
                    start=start+1;
                }else
                //CHECK SMALLEST FROM RIGHT SORTED PART OF ARRAY 
                {
                    if(arr[mid]<=smallest){
                        smallest=arr[mid];  
                        index=mid;
                    }
                    end=end-1;
                }
             }
            return index;
    	}
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends