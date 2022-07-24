class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    int dp[n+1][sum+1];
	    //now filling matrix based on subset sum
	    dp[0][0]=1;
	    for(int i=1;i<=sum;i++) dp[0][i]=0;
	    for(int i=1;i<=n;i++) dp[i][0]=1;
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j) dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            else dp[i][j]=dp[i-1][j];
	        }
	    }
	    
	    //now just traversing last row till sum/2, and finding minimum sum;
	    //we have to minimise Totalsum-2*(current sum of a subset)
	    int minDiff=INT_MAX;
	    for(int i=0;i<=sum/2;i++){
	        if(dp[n][i]==1){
	            minDiff=min(sum-2*i,minDiff);
	        }
	    }
	    return minDiff;
	    
	} 
};