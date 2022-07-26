class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[205][205];
    int solve(int n, int f){
        // your code here
        if(n==1) return f;
        if(f==0||f==1) return f;
        
        if(dp[n][f]!=-1) return dp[n][f];
        
        int minAns=205; //more than max floors (ek trike se INT_MAX hi maan lo)
        for(int k=1;k<=f;k++){
            int temp=max(solve(n-1,k-1),solve(n,f-k))+1;
            minAns=min(temp,minAns);
        }
        dp[n][f]=minAns;
        return minAns;
    }
    int eggDrop(int n, int f) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,f);
    }
};