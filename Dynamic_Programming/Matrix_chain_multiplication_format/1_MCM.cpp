class Solution{
    private:
    int helper(int *arr,int i, int j){
        if(i>=j) return 0; //becoz -ive or 1 size array not suitable;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int minAns=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int tempAns=helper(arr,i,k) + helper(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            minAns=min(minAns,tempAns);
        }
        return dp[i][j]=minAns;  //storing minAns for this 'i' and 'j' combination
    }
public:
    int dp[101][101];
    int matrixMultiplication(int N, int arr[])
    {
        //int dp[N+1][N+1]; // dp[i][j]
        memset(dp,-1,sizeof(dp));
        
        return helper(arr,1,N-1);
    }
};