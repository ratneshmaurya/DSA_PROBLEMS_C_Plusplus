// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        
        // first counting all numbers which are close to k
        int i,count=0;
        for(i=0;i<n;i++){
            if(arr[i]<=k) count++;
        }
        i=0;
        // now counting the numbers which are not close to 'k' in that window
        int unclose;
        for(i=0;i<count;i++){
            if(arr[i]>k)
                unclose++;
        }
        int j,min_swap=unclose;
        min_swap=min(unclose,min_swap);
        for(i=0,j=count;j<n;i++,j++){
            if(arr[j]>k) unclose++;
            if(arr[i]>k) unclose--;
            min_swap=min(unclose,min_swap);
        }
        return min_swap;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends