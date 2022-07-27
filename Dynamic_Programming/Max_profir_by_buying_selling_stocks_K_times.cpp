
class Solution {
    private:
    //do cheej hai, if phle se koi transaction chla aa rha then ,we have two option,
    //either current pr bnd krdo or move further (see the else part)
    //agr phle se transaction nhi chl rha (i.e ongoing=0 hai), then again two option,
    //either take that current and strat from it or skip it move forward to start from 
    //ahead element.
    
    int helper(int K,int N,int A[],int ongoing){
        if(N==0)return 0;
        if(K==0)return 0;
        if(dp[N][K][ongoing]!=-1)return dp[N][K][ongoing];
        int ans;
        if(ongoing==0){
            
            //doing -A[0], becoz taking the current element to start a transaction, hence
            //we have to buy it, thus substracting
            ans=max(helper(K,N-1,A+1,1)-A[0], helper(K,N-1,A+1,ongoing));
        }
        else{
            //doing +A[0], becoz taking the current element to stop a transaction, hence
            //we have to sell it, thus adding its price
            ans=max(helper(K-1,N-1,A+1,0)+A[0], helper(K,N-1,A+1,ongoing));
        }
        dp[N][K][ongoing]=ans;
        return ans;
    }
  public:
  int dp[501][201][2];
    int maxProfit(int K, int N, int A[]) {
        // code here
          //dp[n][k][ongoing or not ?]
        memset(dp,-1,sizeof(dp));
        return helper(K,N,A,0); //initially passing ongoing =0, means ki koi trnsaction start nhi hui
    }
};