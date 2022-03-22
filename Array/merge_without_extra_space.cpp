class Solution{
   
    public:
    
	void merge(int arr1[], int arr2[], int n, int m) 
	{
	    int x=0;
        for(int i=n-1;i>=0;i--){
            if(arr1[i]>arr2[x] && x<m){
                swap(arr1[i],arr2[x]);
                x++;
            }
            else{
                break;
            }
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
    }
};