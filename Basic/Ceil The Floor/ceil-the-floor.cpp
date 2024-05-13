//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int floor=-1;
    int ceil=-1;
    bool firstCeil=false;
    pair<int,int> FloorCeil;
    
        for(int i=0; i<=n-1;i++){
            
            if (arr[i]<=x ){
                int j=arr[i];
                if(j>=floor){
                    floor=j;
                }
                
            }
            if (arr[i]>=x ){
            int j=arr[i];
            if(firstCeil){  //first we will find the first greater number than x then we will check
            //other condition that does it lower than old ceil
                if(j<=ceil){
                    ceil=j;
                }
            }else{
                if(ceil<=j){
                firstCeil=true;
                ceil=j;
                }
            }
            
        }
    
        
    }
    
    FloorCeil.first=floor;
    FloorCeil.second=ceil;
    return FloorCeil;
    
}