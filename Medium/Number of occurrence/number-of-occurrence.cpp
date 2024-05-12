//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	int count(int arr[], int n, int x) {
	    int start = 0;
        int end = n - 1; // Use the provided size of the array
        int freq_count = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == x) {
                int pos = mid;
                freq_count++;
                pos--;
                while (pos >= 0 && arr[pos] == x) {
                    freq_count++;
                    pos--;
                }
                
                pos = mid;
                pos++;
                while (pos < n && arr[pos] == x) {
                    freq_count++;
                    pos++;
                }
                break;
            } else if (arr[mid] > x) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return freq_count;

        
	}
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends