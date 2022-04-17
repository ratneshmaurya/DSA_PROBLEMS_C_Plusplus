class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int res=arr[n-1]-arr[0];
        int maxi,mini;
        for(int i=1;i<n;i++){
            
            // if greater than k, then only do -k concept in arr[i], else humara 
            // assumption toh chl hi rha ki +k kiya hai smaller elements(which are less than k) me;
            if(arr[i]>=k){
                maxi=max(arr[i-1]+k,arr[n-1]-k);
                mini=min(arr[0]+k,arr[i]-k);
                res=min(res,maxi-mini);
            }
            else{
                continue;
            }
        }
        return res;
    }
};