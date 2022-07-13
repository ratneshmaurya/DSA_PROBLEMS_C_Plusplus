nt findFloor(long long int arr[], int N, long long int x) {
    
    //Your code here
    int i=0,j=N-1;
    int ans=-1,mid;
    while(i<=j){
        mid=i+ (j-i)/2;
        if(arr[mid]==x) return mid;
        
        else if(arr[mid]<x){ 
            ans=mid; 
            i=mid+1;
        }
        
        else j=mid-1;
    }
    return ans;
}